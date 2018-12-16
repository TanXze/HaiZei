/*************************************************************************
	> File Name: send_file.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月25日 星期日 10时02分14秒
 ************************************************************************/

#include "head.h"
#include "get_conf_value.c"

int send_file(int sockfd, char *file_name) {
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
