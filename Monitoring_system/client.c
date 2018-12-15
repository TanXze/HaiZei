#include "head.h"
//#include "get_conf_value.c"
#include "send_ask.c"

#define BUFFER_SIZE 1024
#define FILE_SIZE 512
#define INS 3

static pthread_mutex_t mutex[INS + 1] = PTHREAD_MUTEX_INITIALIZER;

struct mypara {
	const char *s;
	int num;
}

int connect_socket(char *host, char *port) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(port));
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr * )&dest_addr, sizeof(dest_addr))) {
        perror("Connect Error");
        return -1;
    }
    return sockfd;
}

/*int socket_listen(char *port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = atoi(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        perror("Bind Error");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        perror("Listen Error");
        return -1;
    }
    return sockfd;
}*/

/*void *func (void *argv) {
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
					 sprintf(bashFileName[n++], "bash ./shell/CPU.sh");
					 sprintf(bashFileName[n++], "bash ./shell/Memlog.sh");
				 }break;
		case 1 : {
					 n = 3; 
					 waittime = 60;
					 sprintf(bashFileName[n++], "bash ./shell/Disk.sh");
					 sprintf(bashFileName[n++], "bash ./shell/System.sh");
					 sprintf(bashFileName[n++], "bash ./shell/Users.sh");
				 }break;
		case 2 : {
					 n = 1; 
					 waittime = 30;
					 sprintf(bashFileName[n++], "bash ./shell/Process.sh");
				 }break;
		default : printf("Para->num Error!\n"); break;
	}
	FILE *fp;
	char buffer[BUFFER_SIZE];
	while (1) {
		for (int i = 0; i < n; i++) {
			pthread_mutex_lock(&mutex[para->num]);
			fp = popen(bashFileName, "r");
			pclose(fp);
			pthread_mutex_unlock(&mutex[para->num]);
		}
		sleep(waittime);
	}
	return ;
}*/

int main() {
    int sock_client;
    struct sockaddr_in dest_addr;
	char *master_host = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "master_host", master_host);
	char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    if ((sock_client = connect_socket(master_host, client_port)) < 0) {
        perror("Connect Error");
        return -1;
    }
    printf("Connect Master Success!\n");
	close(sock_client);
	pthread_t t[INS + 1];
	struct mypara para[INS + 1];
	for (int i = 0; i < 3; i++) {
		para[i].s = "Check";
		para[i].num = i;
		if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
			printf("Pthread Create Error!\n");
			exit(1);
		}
	}
	char *connect_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
    int sock_listen = socket_listen(connect_port);
    while (1) {
		struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sock_client= accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            break;
        }
		printf("Master Connect Success!\n");
        /*char buffer[BUFFER_SIZE];
        bzero(buffer, sizeof(buffer));
        while (recv(sock_client, buffer, BUFFER_SIZE, 0) > 0) {
            client_ask(sock_client, buffer);
        }*/

        close(sock_client);
	}
	close(sock_listen);
}
