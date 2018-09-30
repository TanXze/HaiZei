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
#define FILE_NAME_MAX_SIZE 512

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
            while (recv(sock_server, buffer, MAX_SIZE, 0) > 0) {
                char buf_send[20], buf_recv[20];
                if (strcmp(buffer, "100") == 0) {
                    bzero(buffer, sizeof(buffer));
                    int sock_short = socket(AF_INET, SOCK_STREAM, 0);
                    strcpy(buf_send, "1");
                    send(sock_short, buf_send, sizeof(buf_send), 0);
                    bzero(buf_send, sizeof(buf_send));
                    int length = recv(sock_short, buffer, sizeof(buffer), 0);
                    printf("%s", buffer);
                    FILE *fcpu = fopen("CPU.log", "w");
                    fwrite(buffer, sizeof(char), length, fcpu);
                    close(sock_short);
                }

                /*if (strcmp(buffer, "101") == 0) {
                    bzero(buffer, sizeof(buffer));
                    int sock_short = socket(AF_INET, SOCK_STREAM, 0);
                    strcpy(buf_send, "2");
                    send(sock_short, buf_send, sizeof(buf_send), 0);
                    bzero(buf_send, sizeof(buf_send));
                    printf("%s", buffer);
                    FILE *fdisk = fopen("DISK.log", "w");
                    fwrite(buffer, sizeof(char), sizeof(buffer), fdisk);
                    close(sock_short);
                }

                if (strcmp(buffer, "102") == 0) {
                    bzero(buffer, sizeof(buffer));
                    int sock_short = socket(AF_INET, SOCK_STREAM, 0);
                    strcpy(buf_send, "3");
                    send(sock_short, buf_send, sizeof(buf_send), 0);
                    bzero(buf_send, sizeof(buf_send));
                    printf("%s", buffer);
                    FILE *fmem = fopen("MEM.log", "w");
                    fwrite(buffer, sizeof(char), sizeof(buffer), fmem);
                    close(sock_short);
                }*/

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
                while (length = recv(sock_server, buffer, MAX_SIZE, 0)) {
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
