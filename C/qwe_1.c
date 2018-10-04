/*************************************************************************
	> File Name: qwe_1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 16时23分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *error_msg = NULL;

int app_name_valid(int argc, char **argv) {
    int ret = 0;
    while (i > 0 && argv[0][i - 1] != '/') --i;
    ret = ret || strcmp(argv[0] + i, "haizeix") == 0;
    return ret;
}

int user_name_valid(char **env) {
    int ret = 0;
    for (char **p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=tanxiaoze") == 0;
    }
    error_msg =(char *)(ret ? NULL : "wrong user-name");
    return ret;
}

int main(int argc, char *argv[], char *env[]) {
    if (app_name_valid(argc, argv) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    printf("Hello World\n");
    return 0;
}
