/*************************************************************************
	> File Name: send_file.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 10时02分14秒
 ************************************************************************/

#include "head.h"
#include "connect_socket.c"

int send_file(char *file_name, struct sockaddr_in addr) {
	char *short_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "short_port", short_port);
    int sockfd;
    if ((sockfd = connect_socket(addr)) < 0) {
        perror("Connect Error");
        return -1;
    }
    //char file_name[FILE_NAME_MAX_SIZE + 1];
    //bzero(file_name, sizeof(file_name));
    //printf("Please input file name on server : \t");
    //strncpy(file_name, buffer, strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));
    //scanf("%s", file_name);

    FILE *fp = fopen(file_name, "r");
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
        send(sock_client, buffer, num_fread, 0);
        bzero(buffer, sizeof(buffer));
        close(sock_client);
    }
    fclose(fp);
    printf("Send File:\t%s Successful!\n", file_name);
}
