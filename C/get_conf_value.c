/*************************************************************************
	> File Name: get_conf_value.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 11时02分21秒
 ************************************************************************/

#include <stdio.h>
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
}

int main() {
    char a[100];
    get_conf_value("/home/tanxiaoze/HaiZei/C/test", "qwe", a);
    return 0;
}
