/*************************************************************************
	> File Name: socket_client.c
	> Author: tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月23日 星期日 16时43分25秒
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

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int sock_client;
char buffer[BUFFER_SIZE];
struct sockaddr_in server_addr;

int socket_creat(int sockfd) {
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect");
        return -1;
    }
}

int main(int argc, char *argv[]) {
    //int sock_client;
    //char buffer[MAX_SIZE];
    //struct sockaddr_in server_addr;
    int port = atoi(argv[2]);
    char *host = argv[1];

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    socket_creat(sock_client);
    printf("Connect success!\n");

    while (1) {
        scanf("%[^\n]s\n", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
    }

    /*while (1) {
        int socket_cpu = socket(AF_INET, SOCK_STREAM, 0);
        connect(socket_cpu, (struct sockaddr *)&server_addr, sizeof(server_addr));
        sleep(5);
    }*/

    /*while (1) {
        char file_name[FILE_NAME_MAX_SIZE + 1];
        bzero(file_name, sizeof(file_name0));
        printf("Please input file name on server : \t");
        strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
        scanf("%s", file_name);

        FILE *fp = fopen(file_name, "r");
        if (NULL == fp) {
            printf("File: %s Not Found!\n", file_name);
        } else {
            bzero(buffer, sizeof(buffer));
            while (!feof(fp)) {
                int num_fread = fread(buffer, sizeof(char), 1, fp);
                if (num_fread < 0) {
                    perror("Fread");
                    return -1;
                }
                send(sock_client, buffer, num_fread, 0);
                bzero(buffer, sizeof(buffer));
                close(sock_client);
            }

            fclose(fp);
            printf("Receive file:\t%s successful!\n", file_name);

        }
    }*/
    close(sock_client);
    return 0;
}
