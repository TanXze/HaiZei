/*************************************************************************
	> File Name: client_ask.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 18时35分50秒
 ************************************************************************/

#include "head.h"
#include "send_file.c"

void client_ask(int sockfd, char *buffer) {
    char *answer = (char *)malloc(sizeof(char) * 30);
    bzero(answer, sizeof(answer));
    if (strcmp(buffer, "100") == 0) {
        printf("Master Check CPU\n");
        if (access("CPU.log", 0) == 0) {
            strcpy(answer, "101");
            printf("CPU.log Can Send\n")
        } else {
            strcpy(answer, "102");
            printf("CPU.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "103") == 0) {
        printf("Send File CPU.log\n");
        send_file("CPU.log");
    } else if (strcmp(buffer, "200") == 0) {
        printf("Master Check Memory\n");
        if (access("Mem.log", 0) == 0) {
            strcpy(answer, "201");
            printf("Mem.log Can Send\n");
        } else {
            strcpy(answer, "202");
            printf("Mem.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "203") == 0) {
        printf("Send File Mem.log\n");
        send_file("Mem.log");
    } else if (strcmp(buffer, "300") == 0) {
        printf("Master Check Disk\n");
        if(access("Disk.log", 0) == 0) {
            strcpy(answer, "301");
            printf("Disk.log Can Send\n");
        } else {
            strcpy(answer, "302");
            printf("Disk.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "303") == 0) {
        printf("Send File Disk.log\n");
        send_file("Disk.log");
    } else {
        printf("Ask Error\n");
    }
    free(answer);
}
