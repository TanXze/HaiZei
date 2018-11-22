/*************************************************************************
	> File Name: master_2.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月20日 星期二 14时37分11秒
 ************************************************************************/

//编译-lpthread

#include "head.h"
#include "get_conf_value.c"
#define INS 5

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
		printf("%s\n", temp);
	    int min = find_min(INS, queue);
        Node *p, ret;
        p = init_node(port, temp);
        ret = insert(linkedlist[min], p, queue[min]);
        queue[min]++;
        linkedlist[min] = ret.next;
        memset(temp, 0, sizeof(temp));
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
    char logfile[20];
    sprintf(logfile, "%d.log", num);
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
    printf("\n");
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

int connect_socket(struct sockaddr_in dest_addr) {
	char *connect_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error!\n");
        return -1;
    }
	dest_addr.sin_port = atoi(connect_port);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect() error\n");
        return -1;
    }
    return sockfd;
}

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in sock_addr;
    struct linger m_sLinger;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error!\n");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char *)&m_sLinger, sizeof(struct linger));
    if ((bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(struct sockaddr))) < 0) {
        close(sockfd);
        perror("bind() error!\n");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error!\n");
        return -1;
    }
    return sockfd;
}

void *func(void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    Node *p, *q, ret;
    //p = linkedlist[para->num];
    //q = linkedlist[para->num];
    int sockfd = -1;
    int count = 0, n = 0, length = queue[para->num];
    /*while (p) {
        sockfd = connect_socket(q->addr);
        if (sockfd < 0) {
            printf("delete %s\n", inet_ntoa(p->addr.sin_addr));
            q = delete_node(q, count);
			queue[para->num]--;
        } else {
            count++;
            printf(" %s is connecting\n", inet_ntoa(p->addr.sin_addr));
        }
		p = p->next;
        close(sockfd);
    }*/
	while (n < length) {
		sockfd = connect_socket(linkedlist[para->num]->addr);
		if (sockfd < 0) {
			printf("delete %s\n", inet_ntoa(linkedlist[para->num]->addr.sin_addr));
			linkedlist[para->num] = delete_node(linkedlist[para->num], count);
			queue[para->num]--;
		} else {
			count++;
			printf("%s is connecting\n", inet_ntoa(linkedlist[para->num]->addr.sin_addr));
		}
		n++;
		close(sockfd);
	}
    //linkedlist[para->num] = q;
    output(linkedlist[para->num], para->num);
    //clear(p);
    //clear(q);
    return NULL;
}

int main() {
    pthread_t t[INS + 1];
    struct mypara para[INS + 1];
    init();
    int server_listen,sockfd, port, pid;
    char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);
    port = atoi(client_port);
    server_listen = create_socket(port);
    for (int i = 0; i < INS; ++i) {
        para[i].s = "check";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
    }
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept error!\n");
            break;
        }
        int min = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->addr = client_addr;
        p->next = NULL;
        ret = insert(linkedlist[min], p, queue[min]);
		queue[min]++;
        output(linkedlist[min], para->num);
        linkedlist[min] = ret.next;
		if (pthread_kill(t[min], 0) == ESRCH) {
			para[min].s = "check";
        	para[min].num = min;
	        if (pthread_create(&t[min], NULL, func, (void *)&para[min]) == -1) {
				printf("error\n");
				exit(1);
			}
		}
        close(sockfd);
    }
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);
    close(server_listen); 
    return 0;
}