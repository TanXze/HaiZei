/*************************************************************************
	> File Name: socket_1.c
	> Author: caohaiyan
	> Mail: 877022406@qq.com
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

#define MAX_SIZE 2000
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

    if (connect(sock_client, (struct sockaddr * ) & server_addr, sizeof(server_addr))) {
        perror("Connect");
        return -1;
    }
    printf("Connect success!\n");

/*    while (1) {
        scanf("%[^\n]s", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
    }*/
    
    char file_name[FILE_NAME_MAX_SIZE + 1];
    bzero(file_name, FILE_NAME_MAX_SIZE + 1);
    printf("Please input file name on server : \t");
    scanf("%s", file_name);

    if (send(sock_client, buffer, MAX_SIZE, 0) < 0) {
        perror("Send");
        return -1;
    }

    FILE *fd = fopen(file_name, "r");
    
    bzero(buffer, MAX_SIZE);
    int num_fread = fread(buffer, 1, MAX_SIZE, fd);
    while (1) {
        if (num_fread < 0) {
            perror("Fread");
            return -1;
        }
        send(sock_client, buffer, strlen(buffer), 0);
        bzero(buffer, MAX_SIZE);
    }
    printf("Receive file:\t%s from server ip successful!\n", file_name);
    close(sock_client);
    return 0;
}

//谭小泽
