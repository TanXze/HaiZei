/*************************************************************************
	> File Name: socket_server.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月25日 星期二 10时49分05秒
 ************************************************************************/

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

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_server;
    char buffer[MAX_SIZE];
    struct sockaddr_in server_addr, client_addr;
    int port = atoi(argv[1]);

    if ((sock_server = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind(sock_server, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind");
        return -1;
    }

    if (listen(sock_server, 20) < 0) {
        perror("Listen");
        return -1;
    }
    
    int size = sizeof(client_addr);
    int sock_accept = accept(sock_server, (struct sockaddr *) &client_addr, &size);
    if (sock_accept < 0) {
        perror("Accept");
        return -1;
    }
    printf("Accept success!\n");

    while (1) {
        if ((recv(sock_accept, buffer, MAX_SIZE, 0)) < 0) {
            perror("Recv");
            return -1;
        }
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    close(sock_server);
    return 0;
}
