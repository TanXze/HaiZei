/*************************************************************************
	> File Name: send_response.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 16时35分42秒
 ************************************************************************/

#include <stdio.h>

int send_response(int socket, int req) {
    char buffer[10] = req;
    if (send(socket, buffer, sizeof(char), 0) < 0) {
        perror("send error");
        return -1;
    } else if (send(socket, buffer, sizeof(char), 0) == 0) {
        perror("connect off");
        return -1;
    } else {
        return 1;
    }
}
