/*************************************************************************
	> File Name: master_2.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月20日 星期二 14时37分11秒
 ************************************************************************/

//编译-lpthread

#include "head.h"
#include "get_conf_value.c"

#ifdef DEBUG
#define DBGprint(...) printf(__VA_ARGS__)
#else
#define DBGprint(...)
#endif

#define INS 5
#define BUFFER_SIZE 1024

typedef struct Node {
    struct sockaddr_in addr; 
    struct Node *next;
} Node, *LinkedList;

struct mypara { 
    char *s;
    int num;
};

int queue[INS + 1] = {0};
LinkedList linkedlist[INS + 5]; 
FILE *log1[INS + 1]; 
static pthread_mutex_t mutex[INS + 1] = PTHREAD_MUTEX_INITIALIZER;

Node *init_node(int port, char *IP) {
    struct sockaddr_in init_addr;
    init_addr.sin_family = AF_INET;
    init_addr.sin_port = htons(port);
    init_addr.sin_addr.s_addr = inet_addr(IP);
    Node *p = (Node *)malloc(sizeof(Node));
    p->addr = init_addr;
    p->next = NULL;
    return p;
}

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
    }
    return ret;
}

int find_min(int N, int *arr) {
    int *min = arr;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (*(arr + i) < *min) {
            min = arr + i;
            ans = i;
        }
    }
    return ans;
}

void init() {
    char *buffer = (char *)malloc(sizeof(char) * 20);
    char *port_buf = (char *)malloc(sizeof(char) * 5);
    char *temp = (char *)malloc(sizeof(char) * 20);
    get_conf_value("./piheadlthd.conf", "prename", buffer);
    get_conf_value("./piheadlthd.conf", "client_port", port_buf);
    int port = atoi(port_buf);
    for (int i = 51; i <= 100; i++) {
        sprintf(temp, "%s.%d", buffer, i);
	    int min = find_min(INS, queue);
        Node *p, ret;
        p = init_node(port, temp);
        ret = insert(linkedlist[min], p, queue[min]);
        queue[min]++;
        linkedlist[min] = ret.next;
        bzero(temp, strlen(temp));
    }
    free(temp);
    free(buffer);
    free(port_buf);
    return ;
}

Node *delete_node(LinkedList head, int index) {
    if (head == NULL) return head;
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head = head->next;
        free(current_node);
        return head;
    }
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}

void output(LinkedList head, int num) {
    Node *p = head;
    char logfile[50];
    sprintf(logfile, "./master_logfile/%d.log", num);
    log1[num] = fopen(logfile, "w");
    char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    while (p) {
        fprintf(log1[num], "%s:%s", inet_ntoa(p->addr.sin_addr), client_port);
        if (p->next) {
            fprintf(log1[num], "%s", "\n");
        }
        p = p->next;
    }
    fclose(log1[num]);
    DBGprint("\n");
}

void clear(LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

int connect_socket(int port, struct sockaddr_in dest_addr) {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        DBGprint("Socket Error\n");
        return -1;
    }
    dest_addr.sin_port = port;
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        DBGprint("Connect Error\n");
        return -1;
    }
    return sockfd;
}

int socket_listen(char *port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        DBGprint("Socket Error\n");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(atoi(port));
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        DBGprint("Bind Error\n");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        DBGprint("Listen Error\n");
        return -1;
    }
    return sockfd;
}

void getfilename(int ack, char *filename) {
    switch (ack) {
        case 100 : {
            sprintf(filename, "CPU.log");
        } break;
        case 200 : {
            sprintf(filename, "Mem.log");
        } break;
        case 300 : {
            sprintf(filename, "Disk.log");
        } break;
        case 400 : {
            sprintf(filename, "System.log");
        } break;
        case 500 : {
            sprintf(filename, "User.log");
        } break;
        case 600 : {
            sprintf(filename, "Process.log");
        } break;
        default : {
            DBGprint("Ack Error!\n");
        } break;
    }
}

void *func(void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    while (1) {
        if (!queue[para->num]) {
            sleep(5);
            continue;
        }
        sleep(5);
        pthread_mutex_lock(&mutex[para->num]);
        int sockfd;
        int count = 0, ack, req, len;
		Node *p = linkedlist[para->num];
		Node *q = linkedlist[para->num];
	    char *connect_port = (char *)malloc(sizeof(char) * 5);
        get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
        int long_port = atoi(connect_port);
	    while (q) {
            ack = 100;
		    sockfd = connect_socket(long_port, q->addr);
		    if (sockfd < 0) {
			    DBGprint("Delete %s\n", inet_ntoa(q->addr.sin_addr));
				q = q->next;
			    p = delete_node(p, count);
			    queue[para->num]--;
				close(sockfd);
				continue;
		    } 
			count++;
		    DBGprint("%s is Connecting\n", inet_ntoa(q->addr.sin_addr));
            send(sockfd, &ack, 4, 0);
            char *filename = (char *)malloc(sizeof(char) * 100);
            getfilename(ack, filename);
            char path[50], commond[50];
            sprintf(path, "./master_logfile/%s", inet_ntoa(q->addr.sin_addr));
            strcat(path, "/");
            sprintf(commond, "mkdir %s", path);
            if (access(path, 0) != 0) {
                FILE *fp = popen(commond, "r");
				pclose(fp);
            }
            while (len = (recv(sockfd, &req, 4, 0)) > 0) {
				if (req != 404) {
                	sleep(5);
                    int short_socket;
                	char *short_port = (char *)malloc(sizeof(char) * 5);
                	get_conf_value("./piheadlthd.conf", "short_port", short_port);
                	int port = atoi(short_port);
                	short_socket = connect_socket(port, q->addr);
                	if (short_socket < 0) {
                        DBGprint("Send File Connect Error!\n");
                    	close(short_socket);
                	}
                	char buffer[BUFFER_SIZE];
                	bzero(buffer, sizeof(buffer));
                	char pathfile[100];
                	sprintf(pathfile, "%s%s", path, filename);
                    FILE *fp = fopen(pathfile, "a+");
                	if (NULL == fp) {
                    	DBGprint("File:\t%s Can Not Open To Write!\n", pathfile);
                	}
                	int length = 0;
                	while ((length = recv(short_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                        if (fwrite(buffer, sizeof(char), length, fp) < length) {
                        	DBGprint("Fail:\t%s Write Failed!\n", pathfile);
                        	break;
                    	}
                    	bzero(buffer, sizeof(buffer));
                	}
                	fclose(fp);
                    if (length == 0) {
                    	DBGprint("Receive File To Path :\t%s From Client :\t %s Successfully!\n", pathfile, inet_ntoa(q->addr.sin_addr));
                	} else if (length < 0) {
                    	DBGprint("Recv Error!\n");
                        break;
                	}
                	bzero(filename, strlen(filename));
                    close(short_socket);
                	ack += 100;
                	if (ack == 700) break;
                	send(sockfd, &ack, 4, 0);
                	getfilename(ack, filename);
            	} else if (req == 404) {
                    ack += 100;
					if (ack == 700) break;
					send(sockfd, &ack, 4, 0);
					getfilename(ack, filename);
				}
			}
		    q = q->next;
		    close(sockfd);
	    }
		linkedlist[para->num] = p;
        output(linkedlist[para->num], para->num);
        pthread_mutex_unlock(&mutex[para->num]);
    }
    return NULL;
}

void *alarm_func(void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    int alarm_socket, sockfd;
    char *alarm_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "alarm_port", alarm_port);
    alarm_socket = socket_listen(alarm_port);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(alarm_socket, (struct sockaddr *)&client_addr, &len)) < 0) {
            DBGprint("Accept Error!\n");
            break;
        }
        char path[50], commond[50];
        sprintf(path, "./master_logfile/%s", inet_ntoa(linkedlist[para->num]->addr.sin_addr));
        strcat(path, "/");
        sprintf(commond, "mkdir %s", path);
        if (access(path, 0) != 0) {
            FILE *fp = popen(commond, "r");
			pclose(fp);
        }
        char buffer[BUFFER_SIZE];
        bzero(buffer, sizeof(buffer));
        char pathfile[100], filename[50];
        sprintf(filename, "warning.log");
        sprintf(pathfile, "%s%s", path, filename);
        FILE *fp = fopen(pathfile, "a+");
        if (NULL == fp) {
            DBGprint("File:\t%s Can Not Open To Write!\n", pathfile);
        }
        int length = 0;
        while ((length = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            if (fwrite(buffer, sizeof(char), length, fp) < length) {
                DBGprint("Fail:\t%s Write Failed!\n", pathfile);
                break;
            }
            bzero(buffer, sizeof(buffer));
        }
        fclose(fp);
        if (length == 0) {
            DBGprint("Receive File To Path :\t%s From Client :\t %s Successfully!\n", pathfile, inet_ntoa(linkedlist[para->num]->addr.sin_addr));
        } else if (length < 0) {
            DBGprint("Recv Error!\n");
        }
        close(sockfd);
        bzero(filename, sizeof(filename));
    }
    close(alarm_socket);
	return NULL;
}

int main() {
    pid_t id = fork();
    if (id < 0) {
        perror("fork()");
    } else if (id > 0) {
        exit(0);
    }
    pthread_t t[INS + 1];
    struct mypara para[INS + 1];
    init();
    int server_listen, sockfd, pid;
    char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    server_listen = socket_listen(client_port);

    for (int i = 0; i < INS; ++i) {
        para[i].s = "Check";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            DBGprint("Pthread Create Error\n");
            exit(1);
        }
    }

	pthread_t alarm_t;
    if (pthread_create(&alarm_t, NULL, alarm_func, NULL) == -1) {
        DBGprint("Alarm Pthread Created Error\n");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            DBGprint("Accept Error!\n");
            break;
        }
        int min = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->addr = client_addr;
        p->next = NULL;
        pthread_mutex_lock(&mutex[min]);
        DBGprint("insert %s in pthread %d\n", inet_ntoa(p->addr.sin_addr), min);
        ret = insert(linkedlist[min], p, queue[min]);
		queue[min]++;
        output(linkedlist[min], para->num);
        linkedlist[min] = ret.next;
        pthread_mutex_unlock(&mutex[min]);
        close(sockfd);
    }
    for (int i = 0; i < INS; i++) {
        pthread_join(t[i], NULL);
    }
    close(server_listen); 
    return 0;
}
