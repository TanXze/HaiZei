#include "head.h"
#include "get_conf_value.c"

#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

#define BUFFER_SIZE 1024
#define FILE_SIZE 512
#define INS 3

static pthread_mutex_t mutex[INS + 1] = PTHREAD_MUTEX_INITIALIZER;

struct mypara {
	const char *s;
	int num;
};

int connect_socket(char *host, char *port) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        DBGprint("Socket Error");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(port));
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr * )&dest_addr, sizeof(dest_addr))) {
        DBGprint("Connect Error");
        return -1;
    }
    return sockfd;
}

int socket_listen(char *port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        DBGprint("Socket Error");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = atoi(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        DBGprint("Bind Error");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        DBGprint("Listen Error");
        return -1;
    }
    return sockfd;
}
   
void get_filename (int ack, char *filename) {
    switch (ack) {
        case 100: {
            sprintf(filename, "./shell/logfile/CPU.log");
        } break;
        case 200: {
            sprintf(filename, "./shell/logfile/Mem.log");
        } break;
        case 300: {
            sprintf(filename, "./shell/logfile/Disk.log");
        } break;
        case 400: {
            sprintf(filename, "./shell/logfile/System.log");
        } break;
        case 500: {
            sprintf(filename, "./shell/logfile/User.log");
        } break;
        case 600: {
            sprintf(filename, "./shell/logfile/Process.log");
        } break;
        default : {
            DBGprint("Ack Error!\n"); break;
        }
    }
}

void *func(void *argv) {
	struct mypara *para;
	para = (struct mypara *) argv;
	char **bashFileName = (char **)malloc(sizeof(char *) * (INS + 1));
	for (int i = 0; i < 3; i++) {
		bashFileName[i] = (char *)malloc(sizeof(char) * 30);
	}
	int n = 0, m = 0, waittime;
	switch(para->num) {
		case 0 : {
					 n = 2; 
					 waittime = 5; 
					 sprintf(bashFileName[m++], "bash ./shell/CPU.sh");
					 sprintf(bashFileName[m++], "bash ./shell/Memlog.sh");
				 }break;
		case 1 : {
					 n = 3; 
					 waittime = 60;
					 sprintf(bashFileName[m++], "bash ./shell/Disk.sh");
					 sprintf(bashFileName[m++], "bash ./shell/System.sh");
					 sprintf(bashFileName[m++], "bash ./shell/Users.sh");
				 }break;
		case 2 : {
					 n = 1; 
					 waittime = 30;
					 sprintf(bashFileName[m++], "bash ./shell/Process.sh");
				 }break;
		default : DBGprint("Para->num Error!\n"); break;
	}
	FILE *fp;
	while (1) {
		for (int i = 0; i < n; i++) {
			pthread_mutex_lock(&mutex[para->num]);
			fp = popen(bashFileName[i], "r");
			pclose(fp);
			pthread_mutex_unlock(&mutex[para->num]);
		}
		sleep(waittime);
	}
    return NULL;
}

void *alarm_func(void *argv) {
    char bashFileName[50], filename[50];
    sprintf(bashFileName, "bash ./shell/Alarm.sh");
    sprintf(filename, "./shell/logfile/warning.log");
    FILE *fp, *fd;
    while (1) {
        fp = popen(bashFileName, "r");
        pclose(fp);
        sleep(5);
        fd = fopen(filename, "r");
        char ch;
        if (fd != NULL) {
            int alarm_socket;
	        char *master_host = (char *)malloc(sizeof(char) * 20);
            get_conf_value("./piheadlthd.conf", "master_host", master_host);
	        char *alarm_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "client_port", alarm_port);
            if ((alarm_socket = connect_socket(master_host, alarm_port)) < 0) {
                DBGprint("Connect Error");
                return NULL;
            }
            DBGprint("Alarm Connect Success!\n");
            char buffer[BUFFER_SIZE];
            bzero(buffer, sizeof(buffer));
            while (!feof(fd)) {
                int num_fread = fread(buffer, 4, 1, fd);
                if (num_fread < 0) {
                    DBGprint("Fread Alarm Error");
                }
                int x = send(alarm_socket, buffer, num_fread, 0);
                bzero(buffer, sizeof(buffer));
            }
            fclose(fd);
            if (remove(filename) != 0) {
                DBGprint("Remove Error");
            }
            close(alarm_socket);
    	    DBGprint("Warning Send Success!\n");
        }
    }
    return NULL;
}

int main() {
    pid_t id = fork();
    if (id < 0) {
        perror("fork()");
    } else if (id > 0) {
        exit(0);
    }
    int sock_client;
    struct sockaddr_in dest_addr;
	char *master_host = (char *)malloc(sizeof(char) * 20);
    get_conf_value("./piheadlthd.conf", "master_host", master_host);
	char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    if ((sock_client = connect_socket(master_host, client_port)) < 0) {
        DBGprint("Connect Error");
        return -1;
    }
    DBGprint("Connect Master Success!\n");
	close(sock_client);

	pthread_t t[INS + 1];
	struct mypara para[INS + 1];
	for (int i = 0; i < 3; i++) {
		para[i].s = "Check";
		para[i].num = i;
		if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
			DBGprint("Pthread Create Error!\n");
			exit(1);
		}
	}

	pthread_t alarm_t;
    if (pthread_create(&alarm_t, NULL, alarm_func, NULL) == -1) {
        DBGprint("Alarm Pthread Create Error!\n");
        exit(1);
    }

	char *connect_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
    int sock_listen = socket_listen(connect_port);
    int ack, short_socket, short_socket_listen;
    char *short_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "short_port", short_port);
    short_socket_listen = socket_listen(short_port);
    while (1) {
		struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sock_client= accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            DBGprint("Accept Error!");
            break;
        }
		DBGprint("Master Connect Success!\n");
        FILE *fp;
        char *filename = (char *)malloc(sizeof(char) * 100);
        while (recv(sock_client, &ack, 4, 0) > 0) {
            fp = NULL;
            get_filename(ack, filename);
            if (access(filename, 0) == 0) {
                ack += 1;
                send(sock_client, &ack, 4, 0);
                DBGprint("%s Can Send!\n", filename);
            } else {
				ack = 404;
				send(sock_client, &ack, 4, 0);
				DBGprint("%s Can Not Send!\n", filename);
				continue;
			}
            if ((short_socket = accept(short_socket_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
                DBGprint("Accept Error!\n");
                break;
            }
            pthread_mutex_lock(&mutex[para->num]);
            FILE *fp = fopen(filename, "r");
            char buffer[BUFFER_SIZE];
            if (NULL == fp) {
                DBGprint("File: %s Not Found!\n", filename);
            } else {
                bzero(buffer, sizeof(buffer));
                while (!feof(fp)) {
                    int num_fread = fread(buffer, sizeof(char), 1, fp);
                    if (num_fread < 0) {
                        DBGprint("Fread Error");
                        return -1;
                    }
                    send(short_socket, buffer, num_fread, 0);
                    bzero(buffer, sizeof(buffer));
                }
                fclose(fp);
                if (remove(filename) != 0) {
                    DBGprint("Remove Error");
                }
                close(short_socket);
            }
            pthread_mutex_unlock(&mutex[para->num]);
            DBGprint("Send File:\t%s Successful!\n", filename);
        }
        close(sock_client);
	}
    close(short_socket_listen);
	close(sock_listen);
}
