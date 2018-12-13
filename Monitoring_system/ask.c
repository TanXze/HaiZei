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
        if (access("./logfile/CPU.log", 0) == 0) {
            strcpy(answer, "101");
            printf("CPU.log Can Send\n");
        } else {
            strcpy(answer, "102");
            printf("CPU.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "103") == 0) {
        printf("Send File CPU.log\n");
        send_file("./logfile/CPU.log");
    } else if (strcmp(buffer, "200") == 0) {
        printf("Master Check Memory\n");
        if (access("./logfile/Mem.log", 0) == 0) {
            strcpy(answer, "201");
            printf("Mem.log Can Send\n");
        } else {
            strcpy(answer, "202");
            printf("Mem.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "203") == 0) {
        printf("Send File Mem.log\n");
        send_file("./logfile/Mem.log");
    } else if (strcmp(buffer, "300") == 0) {
        printf("Master Check Disk\n");
        if(access("./logfile/Disk.log", 0) == 0) {
            strcpy(answer, "301");
            printf("Disk.log Can Send\n");
        } else {
            strcpy(answer, "302");
            printf("Disk.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "303") == 0) {
        printf("Send File Disk.log\n");
        send_file("./logfile/Disk.log");
    } else if (strcmp(buffer, "400") == 0) {
        printf("Master Check System\n");
        if (access("./logfile/System.log", 0) == 0) {
            strcpy(answer, "401");
            printf("System.log Can Send\n");
        } else {
            strcpy(answer, "402");
            printf("System.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "403") == 0) {
        printf("Send File System.log\n");
        send_file("./logfile/System.log");
    } else if (strcmp(buffer, "500") == 0) {
        printf("Master Check User\n");
        if (access("./logfile/User.log", 0) == 0) {
            strcpy(answer, "501");
            printf("User.log Can Send\n");
        } else {
            strcpy(answer, "502");
            printf("User.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "503") == 0) {
        printf("Send File User.log\n");
        send_file("./logfile/User.log");
    } else if (strcmp(buffer, "600") == 0) {
        printf("Master Check Process\n");
        if (access("./logfile/Process.log", 0) == 0) {
            strcpy(answer, "601");
            printf("Process.log Can Send\n");
        } else {
            strcpy(answer, "602");
            printf("Process.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "603") == 0) {
        printf("Send File Process.log\n");
        send_file("./logfile/Process.log");
    } else {
        printf("Ask Error\n");
    }
    free(answer);
}
