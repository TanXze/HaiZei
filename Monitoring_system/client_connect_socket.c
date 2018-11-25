/*************************************************************************
	> File Name: client_connect_socket.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 14时55分33秒
 ************************************************************************/

#include "head.h"

int connect_socket(char *host, char *port) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        return -1;
    }
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(port));
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr * )&dest_addr, sizeof(dest_addr))) {
        perror("Connect Error");
        return -1;
    }
    return sockfd;
}
