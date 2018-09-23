/*************************************************************************
	> File Name: socket_1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月23日 星期日 16时56分34秒
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
    int sock_client;
    char buffer[MAX_SIZE];
    struct sockaddr_in dest_addr;
    int port = atoi(argv[2]);
    char *host = argv[1];
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock_client, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) > 0) {
        perror("Connect");
        return -1;
    }
    while (1) {
        scanf("%[^\n]s", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
    }
}
