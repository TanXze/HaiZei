#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>		
#include <netinet/in.h>
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

typedef struct Queue {
    char **data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->length = n;
    q->cnt = 0;
    q->data = (char **)malloc(sizeof(char *) * n);
    q->head = 0;
    q->tail = -1;
    return q;
}

int push(Queue *q, char value[]) {
    if (q->cnt == q->length) return 0;
    q->tail++;
    if (q->tail >= q->length) q->tail -= q->length;
    q->data[q->tail] = value;
    q->cnt++;
    return 1;
}

void pop(Queue *q) {
    if (q->head > q->tail) return ;
    q->head++;
    if (q->head >= q->length) q->head -= q->length;
    q->cnt--;
    return ;
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q) {
    for (int i = 0; i < q->cnt; i++) {
        int ind = (q->head + i) % q->length;
        printf("%s\n", q->data[ind]);
    }
    return ;
}

/*#define INS 5

int queue[INS + 1] = {0};

typedef struct Node {
    char *data;
    struct Node *next;
} Node, *LinkedList;

LinkedList linkedlist[INS + 5];

FILE *log1[INS + 1];

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    //ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
        //ret.data = 1;
    }
    return ret;
}

void output(LinkedList head, int num) {
    Node *p = head;
    char logfile[20];
    sprintf(logfile, "%d.log", num);
    log1[num] = fopen(logfile, "w");
    while (p) {
        printf("%s", p->data);
        fprintf(log1[num], "%s", p->data);
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
    for (int i = 0; i < N; i++) {
        if (*(arr + i) < *min) {
            min = arr + i;
            ans = i;
        }
    }
    return ans;
}*/

int main(int argc, char *argv[]) {
    int server_listen, sockfd, port, pid1, pid2;
    struct sockaddr_in sock_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return -1;
    }

    port = atoi(argv[1]);
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(struct sockaddr))) < 0) {
        close(sockfd);
        perror("bind() error\n");
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error");
        return -1;
    }

    server_listen = sockfd;

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((sockfd = accept(server_listen, (struct sockaddr *) &client_addr, &len)) < 0) {
            perror("accept() error");
            break;
        }

        if ((pid1 = fork()) == -1) {
            perror("fork() error\n");
            exit(0);
        }
        if (pid1 == 0) {
            close(server_listen);
            for (int i = 0; i < INS; i++) {
                pid2 = fork();
                if (pid2 == 0 || pid2 == -1) break;
	            exit(0);
            }
            if (pid2 == -1) {
                perror("fork() error\n");
            } else if (pid2 == 0) {
                struct sockaddr_in peer;
                char queue_buff[100];
                socklen_t peer_len = sizeof(struct sockaddr_in);
                bzero(&peer, sizeof(struct sockaddr_in));
                getpeername(sockfd, (struct sockaddr *)&peer, &peer_len);
                char buff_peer[64] = {'\0'};
                inet_ntop(AF_INET, (void*)&peer.sin_addr, buff_peer, 63);
                sprintf(queue_buff, "%s:%d", buff_peer, port);

                /*int sub = find_min(INS, queue);
                Node *p, ret;
                p = (Node *)malloc(sizeof(Node));
                p->data = queue_buff;
                p->next = NULL;
                ret = insert(linkedlist[sub], p, queue[sub]);
                queue[sub]++;
                linkedlist[sub] = ret.next;*/
            } 
            close(sockfd);
            exit(0);
        }
        close(sockfd);
    }
    /*for (int i = 0; i < INS; i++) {
        printf("%d ", queue[i]);
        printf(" ... ");
        output(linkedlist[i], i);
    }
    printf("\n");*/
    return 0;
}
