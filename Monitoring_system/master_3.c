/*************************************************************************
	> File Name: master_3.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月18日 星期日 19时59分14秒
 ************************************************************************/

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#include "get_conf_value.c"
#define INS 5

void *func(void *);  //函数声明
int find_min(int N, int *arr);

int queue[INS + 1] = {0}; //初始化队列

typedef struct Node {
    struct sockaddr_in addr; // 地址结构体
    int data;
    struct Node *next;
} Node, *LinkedList;

LinkedList linkedlist[INS + 5]; 

struct mypara {   //每个线程的信息
    char *s;
    int num;
};

FILE *log1[INS + 1]; 

Node insert (LinkedList head, Node *node, int index);

void init () {
    //Node *p = (Node *)malloc(sizeof(Node));
    char *buffer = (char *)malloc(sizeof(char) * 20);
    char *port_buf = (char *)malloc(sizeof(char) * 5);
    char *temp = (char *)malloc(sizeof(char) * 5);
    size_t n = strlen(buffer);
    get_conf_value("./piheadlthd.conf", "prename", buffer);
    get_conf_value("./piheadlthd.conf", "client_port", port_buf);
    int port = atoi(port_buf);
    
    struct sockaddr_in init_addr;

    for (int i = 50; i <= 100; i++) {
        sprintf(temp, "%s.%d", buffer, i);
        printf("%s\n", temp);

	    init_addr.sin_family = AF_INET;
    	init_addr.sin_port = htons(port);
    	init_addr.sin_addr.s_addr = inet_addr(temp);

	    int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        //p->data = temp;
        p->addr = init_addr;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;
        memset(temp, 0, sizeof(temp));
    }
    free(temp);
    free(buffer);
    free(port_buf);
    return ;
}

Node insert (LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
        ret.data = 1;
    }
    return ret;
}

/*void delete_t (LinkedList head, int index) {
    if (index == 0) {
        head = head->next;
        return ;
    }
    index--;
    Node *p = head, delete_node;
    while (p->next && index--) {
        p = p->next;
    }
    if (index == 0) {
        delete_node = p->next;
        p->next = delete_node->next;
        free(delete_node);
    }
    return ;
}*/

void output(LinkedList head, int num) {
    Node *p = head;
    char logfile[20];
    sprintf(logfile, "%d.log", num);
    log1[num] = fopen(logfile, "w");
    while (p) {
        printf("%s", inet_ntoa(p->addr.sin_addr));
        fprintf(log1[num], "%s", inet_ntoa(p->addr.sin_addr));
        if (p->next) {
            printf(" ");
            fprintf(log1[num], "%s", " ");
        }
        p = p->next;
    }
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

int create_socket (int port) {
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

    printf("listening...\n");
    return sockfd;
}

int main() {
    freopen("in.in", "r", stdin); //从in.in中读入数据
    pthread_t t[INS + 1];//存储线程ID
    struct mypara para[INS + 1];//每个线程有一个独立的数据区，不会发生冲突
    int temp; 

    init();
    
    int server_listen,sockfd, port, pid;
    
    char *client_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "client_port", client_port);

    port = atoi(client_port);

    server_listen = create_socket(port);
       

    for (int i = 0; i < INS; ++i) {
        para[i].s = "Hello world!";
        para[i].num = i;//用来标识线程
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {//线程ID（只有在进程环境下有意义）、属性、函数、函数参数（多个参数用结构体），创建结束后值执行结束时间不确定
            printf("error\n");
            exit(1);
        }
        //printf("Current pthread id = %ld \n", t[i]);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept error!\n");
            break;
        }

        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->data = temp;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;   
        
        close(sockfd);
    }

    /*while (scanf("%d", &temp) != EOF) {//主线程起到平衡的作用，选择节点数量最少的链表插入
        int sub = find_min(INS, queue);
        Node *p, ret;
        p = (Node *)malloc(sizeof(Node));
        p->data = temp;
        p->next = NULL;
        ret = insert(linkedlist[sub], p, queue[sub]);
        queue[sub]++;
        linkedlist[sub] = ret.next;
    }*/
    //需要等待子进程结束，否则主线程会先结束，整个进程结束
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_join(t[3], NULL);
    pthread_join(t[4], NULL);

    /*for (int i = 0; i < INS; ++i) {
        printf("%d ", queue[i]);
        printf(" ... ");
        output(linkedlist[i], i);
    }
    printf("\n");*/
    close(server_listen);

    return 0;
}

void *func(void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    //printf("%s %d\n", para->s, para->num);
    Node *p, ret;
    for (int i = para->num; i <= 10; ++i) {
        p = (Node *) malloc(sizeof(Node));
        p->data = i;
        p->next = NULL;
        ret = insert(linkedlist[para->num], p, queue[para->num]);
        queue[para->num]++;
        linkedlist[para->num] = ret.next;
    }
    //output(linkedlist[para->num], para->num);
    return NULL;
}
