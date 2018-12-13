/*************************************************************************
	> File Name: get_conf_value.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 11时02分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_conf_value (char *pathname, char *key_name, char *value) {
    FILE *fp = NULL;
    char *line = NULL, *substr = NULL;
    size_t len = 0, tmplen = 0;
    ssize_t read;

    if (key_name == NULL || value == NULL) {
        printf("Paramer is Invaild!\n");
        exit(-1);
    }
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        printf("Open File Error!\n");
        exit(-1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        substr = strstr(line, key_name);
        if (substr == NULL) 
            continue;
        else {
            tmplen = strlen(key_name);
            if (line[tmplen] == '=') {
                strncpy(value, &line[tmplen + 1], (int)read - tmplen);
                tmplen = strlen(value);
                *(value + tmplen - 1) = '\0';
                break;
            }
            else {
                printf("Maybe There is Something Wrong With File\n");
                continue;
            }
        }
    }
    if (substr == NULL) {
        printf("%s Not Found in File\n", key_name);
        fclose(fp);
        exit(-1);
    }
    free(line);
    fclose(fp);
    return 0;
}
