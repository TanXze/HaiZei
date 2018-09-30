/*************************************************************************
	> File Name: fgets.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 10时17分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_conf_value(char *pathname, char* key_name, char *value) {
    FILE *fp = NULL;
    char *line = NULL, *substr = NULL;
    size_t len = 0, tmplen = 0;
    ssize_t read;

    fp = fopen(pathname, "r");
    if (fp == NULL) {
        perror("Can not open the file!\n");
        return -1;
    }
    
    while ((read = getline(&line, &len, fp)) != -1) {
        substr = strstr(line, key_name);
        if (substr == NULL) {
            continue;
        } else {
            tmplen = strlen(key_name);
            if (line[tmplen] == '=') {
                strncpy(value, &line[tmplen + 1], (int)read - tmplen);
                tmplen = strlen(value);
                *(value + tmplen - 1) = '\0';
                break;
            } else {
                perror("Error");
                continue;
            }
        }
    }

    if (substr == NULL) {
        printf("%s can not find!\n", key_name);
        fclose(fp);
        return -1;
    }

    printf("%s = %s\n", key_name, value);
    free(line);
    fclose(fp);
    return 0;
}

int main() {
    char a[20];
    get_conf_value("/home/tanxiaoze/HaiZei/C/test", "qwe", a);
    printf("%s\n", a);
    return 0;
}
