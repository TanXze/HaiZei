/*************************************************************************
	> File Name: send_file.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 10时02分14秒
 ************************************************************************/

#include "head.h"
#include "get_conf_value.c"

int send_file(int sockfd, char *file_name) {
	/*char *short_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "short_port", short_port);
    char *master_host = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "master_host", master_host);
    int sockfd;
    if ((sockfd = connect_socket_send(master_host, short_port)) < 0) {
        perror("Connect Error");
        return -1;
    }
    int sockfd = socket_listen(short_port);
	struct sockaddr_in master_addr;
    socklen_t len = sizeof(master_addr);
    if ((sock_client= accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
        perror("Accept Error!");
        break;
    }
	printf("Master Short Connect Success! Waiting Send!\n");*/
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
