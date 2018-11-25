/*************************************************************************
	> File Name: recv_file.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 09时25分26秒
 ************************************************************************/

#include "head.h"

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int recv_file(int sock_server, char *buffer, char *file_name, struct sockaddr_in addr, char *file_type) {
    char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    bzero(buffer, sizeof(buffer));
    while (recv(sock_server, buffer, BUFFER_SIZE, 0) > 0) {
        char path[100];
        sprintf(path, "%s", addr);
        strcat(path, "/");
        strcat(path, file_type);
        FILE *fp = fopen(path, "w");
        if (NULL == fp) {
            printf("File:\t%s Can Not Open To Write!\n", path);
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
        printf("Receive File:\t%s To Path :\t%s From Client :\t %s Successfully!\n", file_name, path, addr);
        fclose(fp);
    }
    close(sock_server);
    return 1;
}
