/*************************************************************************
	> File Name: connect_socket.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 10时17分36秒
 ************************************************************************/

#include "head.h"
#include "get_conf_value.c"

int connect_socket(struct sockaddr_in dest_addr) {
	char *connect_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        return -1;
    }
	dest_addr.sin_port = atoi(connect_port);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("Connect Error");
        return -1;
    }
    return sockfd;
}
