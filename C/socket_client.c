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

#define MAX_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char *argv[]) {
    int sock_client;
    char buffer[MAX_SIZE];
    struct sockaddr_in server_addr;
    int port = atoi(argv[2]);
    char *host = argv[1];

    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock_client, (struct sockaddr * ) & server_addr, sizeof(server_addr)) < 0) {
        perror("Connect");
        return -1;
    }
    printf("Connect success!\n");

    /*while (1) {
        scanf("%[^\n]s\n", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
        bzero(buffer, MAX_SIZE);
    }*/

    while (1) {
        char buf_send[20], buf_recv[20];
        strcpy(buf_send, "100");
        int sock_short = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock_short, (struct sockaddr *) & server_addr, sizeof(server_addr));
        send(sock_short, buf_send, sizeof(buf_send), 0);
        bzero(buf_send, sizeof(buf_send));
        int sock_recv = recv(sock_short, buf_recv, sizeof(buf_recv), 0);
        if (sock_recv = 0) {
            printf("Server close\n");
            return -1;
        }
        if (sock_recv > 0) {
            printf("%s", buf_recv);
            if (strcmp(buf_recv, "1") == 0) {
                FILE *fcpu = popen("~/HaiZei/Monitoring_system/CPU.sh","r");
                fgets(buffer, sizeof(buffer), fcpu);
                send(sock_short, buffer, sizeof(buffer), 0);
                bzero(buffer, sizeof(buffer));
                close(sock_short);
            }
        }
        
        /*strcpy(buf_send, "101");
        int sock_shor = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock_shor, (struct sockaddr *) & server_addr, sizeof(server_addr));
        send(sock_shor, buf_send, sizeof(buf_send), 0);
        bzero(buf_send, sizeof(buf_send));
        if (recv(sock_shor, buf_recv, sizeof(buf_recv), 0) > 0) {
            if (strcmp(buf_recv, "2") == 0) {
                FILE *fdisk = popen("~/HaiZei/Monitoring_system/disk.sh", "r");
                fgets(buffer, sizeof(buffer), fdisk);
                send(sock_client, buffer, sizeof(buffer), 0);
                bzero(buffer, sizeof(buffer));
                close(sock_shor);
            }
        }

        strcpy(buf_send, "102");
        int sock_sho = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock_sho, (struct sockaddr *) & server_addr, sizeof(server_addr));
        send(sock_sho, buf_send, sizeof(buf_send), 0);
        bzero(buf_send, sizeof(buf_send));
        if (recv(sock_sho, buf_recv, sizeof(buf_recv), 0) > 0) {
            if (strcmp(buf_recv, "3") == 0) {
                FILE *fmem = popen("~/HaiZei/Monitoring_system/Memlog.sh", "r");
                fgets(buffer, sizeof(buffer), fmem);
                send(sock_client, buffer, sizeof(buffer), 0);
                bzero(buffer, sizeof(buffer));
                close(sock_sho);
            }
        }*/
        
        sleep(5);
    }

    /*while (1) {
        char file_name[FILE_NAME_MAX_SIZE + 1];
        bzero(file_name, FILE_NAME_MAX_SIZE + 1);
        printf("Please input file name on server : \t");
        strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
        scanf("%s", file_name);

        FILE *fp = fopen(file_name, "r");
        if (NULL == fp) {
            printf("File: %s Not Found!\n", file_name);
        } else {
            bzero(buffer, MAX_SIZE);
            while (!feof(fp)) {
                int num_fread = fread(buffer, sizeof(char), 1, fp);
                if (num_fread < 0) {
                    perror("Fread");
                    return -1;
                }
                send(sock_client, buffer, num_fread, 0);
                bzero(buffer, MAX_SIZE);
                close(sock_client);
            }

            fclose(fp);
            printf("Receive file:\t%s successful!\n", file_name);

        }
    }*/
    close(sock_client);
    return 0;
}
