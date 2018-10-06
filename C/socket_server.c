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

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int sock_server;
char buffer[BUFFER_SIZE];
struct sockaddr_in server_addr, client_addr;

int socket_creat(int sockfd) {
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind");
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
        perror("Listen");
        return -1;
    }
    return sockfd;
}

int main(int argc, char *argv[]) {
    int port = atoi(argv[1]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    socket_creat(sock_server);

    int sock_listen = sock_server, pid;
    while (1) {
        socklen_t size = sizeof(client_addr);
        sock_server = accept(sock_listen, (struct sockaddr *) &client_addr, &size);
        if (sock_server < 0) {
            perror("Accept");
            break;
        }

        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        bzero(&peer, sizeof(peer));
        getpeername(sock_server, (struct sockaddr *) &peer, &len);
        char buff_peer[64] = {'\0'};
        inet_ntop(AF_INET, (void *)&peer.sin_addr, buff_peer, 63);
        printf("%s已连接:\n", buff_peer);

        if ((pid = fork()) < 0) {
            printf("Fork");
            return -1;
        }
        if (pid == 0) {
            close(sock_listen);
            while (recv(sock_server, buffer, BUFFER_SIZE, 0) > 0) {
                printf("%s\n", buffer);
                /*bzero(buffer, sizeof(buffer));
                char file_name[FILE_NAME_MAX_SIZE + 1];
                char file_name_save[FILE_NAME_MAX_SIZE + 1];
                bzero(file_name, sizeof(file_name));
                printf("Please Input File Name On Client:\t");
                scanf("%s", file_name);

                printf("Please Input File Name To Save:\t");
                scanf("%s", file_name_save);

                FILE *fp = fopen(file_name_save, "w");
                if (NULL == fp) {
                    printf("File:\t%s Can Not Open To Write!\n", file_name_save);
                    return -1;
                }

                bzero(buffer, sizeof(buffer));
                int length = 0;
                while (length = recv(sock_server, buffer, BUFFER_SIZE, 0)) {
                    if (fwrite(buffer, sizeof(char), length, fp) < length) {
                        printf("Fail:\t%s Write Failed!\n", file_name);
                        break;
                    }
                    bzero(buffer, sizeof(buffer));
                }
                printf("Receive File:\t%s From Client IP Successfully!\n", file_name);*/
            }
            close(sock_server);
            exit(0);
        }
        close (sock_server);
    }
    return 0;
}
