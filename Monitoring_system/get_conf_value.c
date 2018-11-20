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
        printf("paramer is invaild!\n");
        exit(-1);
    }
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        printf("Open config, file, error!\n");
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
                printf("Maybe there is something wrong with config file");
                continue;
            }
        }
    }
    if (substr == NULL) {
        printf("%s not found is config file!\n", key_name);
        fclose(fp);
        exit(-1);
    }
    //printf("%s=%s\n", key_name, value);
    free(line);
    fclose(fp);
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_conf_value(char *pathname, char *key_name, char *value) {
    FILE *fp;
    char *line;
    size_t len = 0;
    ssize_t read;
    int key_name_len, value_len;
    fp = fopen(pathname, "r");
    if (fp == NULL) {
        printf("Can not open the file!\n");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, key_name) == NULL) {
            continue;
        } else {
            key_name_len = strlen(key_name);
            if (line[key_name_len] == '=') {
                strncpy(value, &line[key_name_len + 1], (int)read - key_name_len);
                value_len = strlen(value);
                *(value + value_len - 2) = '\0';
                break;
            } else {
                printf("Error");
                continue;
            }
        }
    }

    if (strstr(line, key_name) == NULL) {
        printf("%s can not find!\n", key_name);
        fclose(fp);
        return -1;
    }

    printf("%s\n", value);
    free(line);
    fclose(fp);
    return 0;
}*/
