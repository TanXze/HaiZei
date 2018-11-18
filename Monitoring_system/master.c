#include <stdio.h>
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
        //int ind = (q->head + i) % q->length;
        printf("%s\n", q->data[i]);
    }
    return ;
}

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

    char queue_buff[100];
    Queue *q = init(10);
    for (int k = 50; k <= 60; k++) {
        sprintf(queue_buff, "192.168.1.%d:%d", k, port);
        printf("%s\n", queue_buff);
        push(q, queue_buff);
    }
    output(q);

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
            for (int i = 0; i < 5; i++) {
                pid2 = fork();
                if (pid2 == 0 || pid2 == -1) break;
	            exit(0);
            }
            if (pid2 == -1) {
                perror("fork() error\n");
            } else if (pid2 == 0) {
                struct sockaddr_in peer;
                socklen_t peer_len = sizeof(struct sockaddr_in);
                bzero(&peer, sizeof(struct sockaddr_in));
                getpeername(sockfd, (struct sockaddr *)&peer, &peer_len);
                char buff_peer[64] = {'\0'};
                inet_ntop(AF_INET, (void*)&peer.sin_addr, buff_peer, 63);
                sprintf(queue_buff, "%s:%d", buff_peer, port);
                pop(q);
                push(q, queue_buff);
                output(q);
            } 
            close(sockfd);
            exit(0);
        }
        close(sockfd);
    }
    clear(q);
    return 0;
}
