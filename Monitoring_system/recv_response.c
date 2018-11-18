/*************************************************************************
	> File Name: recv_response.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 23时35分48秒
 ************************************************************************/

#include <stdio.h>

int recv_response(int socket) {
    int buffer[10];
    if (recv(socket, buffer, sizeof(char), 0) < 0) {
        perror("recv error");
        return -1;
    } else if (recv(socket, buffer, sizeof(char), 0) == 0) {
        perror("connect off");
        return -1;
    } else {
        return buffer;
    }
}
