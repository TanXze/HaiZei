/*************************************************************************
	> File Name: client_ask.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 18时35分50秒
 ************************************************************************/

#include "head.h"
#include "recv_file.c"

int connect_socket_recv(struct sockaddr_in dest_addr) {
	char *short_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "short_port", short_port);
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        return -1;
    }
	dest_addr.sin_port = atoi(short_port);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("Connect Error");
        return -1;
    }
    return sockfd;
}

void master_ask(int sockfd) {
    int short_sockfd;
    char *answer = (char *)malloc(sizeof(char) * 30);
    bzero(answer, sizeof(answer));
    char buffer[BUFFER_SIZE];
    bzero(buffer, sizeof(buffer));
    for (int ack = 100; ack <= 600; ack += 100) {
        strcpy(buffer, ack);
        send(sockfd, buffer, strlen(buffer), 0);

    }
    if (strcmp(buffer, "100") == 0) {
        printf("Master Check CPU\n");
        if (access("./logfile/CPU.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "101");
            printf("CPU.log Can Send\n");
        } else {
            strcpy(answer, "102");
            printf("CPU.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "103") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File CPU.log\n");
        send_file(short_sockfd, "./logfile/CPU.log");
        close(sockfd);
    } else if (strcmp(buffer, "200") == 0) {
        printf("Master Check Memory\n");
        if (access("./logfile/Mem.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "201");
            printf("Mem.log Can Send\n");
        } else {
            strcpy(answer, "202");
            printf("Mem.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "203") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File Mem.log\n");
        send_file(short_sockfd, "./logfile/Mem.log");
        close(sockfd);
    } else if (strcmp(buffer, "300") == 0) {
        printf("Master Check Disk\n");
        if(access("./logfile/Disk.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "301");
            printf("Disk.log Can Send\n");
        } else {
            strcpy(answer, "302");
            printf("Disk.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "303") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File Disk.log\n");
        send_file(short_sockfd, "./logfile/Disk.log");
        close(sockfd);
    } else if (strcmp(buffer, "400") == 0) {
        printf("Master Check System\n");
        if (access("./logfile/System.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "401");
            printf("System.log Can Send\n");
        } else {
            strcpy(answer, "402");
            printf("System.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "403") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File System.log\n");
        send_file(short_sockfd, "./logfile/System.log");
        close(sockfd);
    } else if (strcmp(buffer, "500") == 0) {
        printf("Master Check User\n");
        if (access("./logfile/User.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "501");
            printf("User.log Can Send\n");
        } else {
            strcpy(answer, "502");
            printf("User.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "503") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File User.log\n");
        send_file(short_sockfd, "./logfile/User.log");
        close(sockfd);
    } else if (strcmp(buffer, "600") == 0) {
        printf("Master Check Process\n");
        if (access("./logfile/Process.log", 0) == 0) {
	        char *short_port = (char *)malloc(sizeof(char) * 5);
            get_conf_value("./piheadlthd.conf", "short_port", short_port);
            short_sockfd = socket_listen(short_port);
            strcpy(answer, "601");
            printf("Process.log Can Send\n");
        } else {
            strcpy(answer, "602");
            printf("Process.log Can Not Send\n");
        }
        send(sockfd, answer, strlen(answer), 0);
    } else if (strcmp(buffer, "603") == 0) {
	    struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sockfd = accept(short_sockfd, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("Accept Error!");
            return ;
        }
        printf("Master Short Connect Success! Waiting Send!\n");
        printf("Send File Process.log\n");
        send_file(short_sockfd, "./logfile/Process.log");
        close(sockfd);
    } else {
        printf("Ask Error\n");
    }
    free(answer);
}
