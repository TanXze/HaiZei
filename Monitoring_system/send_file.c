/*************************************************************************
	> File Name: send_file.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 10时02分14秒
 ************************************************************************/

#include "head.h"
#include "get_conf_value.c"

int connect_socket_send(char *host, char *port) {
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

int send_file(char *file_name) {
	char *short_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "short_port", short_port);
    char *master_host = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "master_host", master_host);
    int sockfd;
    if ((sockfd = connect_socket_send(master_host, short_port)) < 0) {
        perror("Connect Error");
        return -1;
    }
    FILE *fp = fopen(file_name, "r");
    char *buffer = (char *)malloc(sizeof(char) * 1024);
    if (NULL == fp) {
        printf("File: %s Not Found!\n", file_name);
    } else {
        bzero(buffer, sizeof(buffer));
        while (!feof(fp)) {
            int num_fread = fread(buffer, sizeof(char), 1, fp);
            if (num_fread < 0) {
                perror("Fread Error");
                return -1;
            }
        send(sockfd, buffer, num_fread, 0);
        bzero(buffer, sizeof(buffer));
        close(sockfd);
        }
    }
    fclose(fp);
    printf("Send File:\t%s Successful!\n", file_name);
    close(sockfd);
    return 1;
}
