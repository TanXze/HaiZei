/*************************************************************************
	> File Name: qwe.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 15时54分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv, char *env[]) {
    int i = strlen(argv[0]);
    while (i > 0 && argv[0][i - 1] != '/') --i;
    if (strcmp(argv[0] + i, "haiziex")) {
        fprintf(stderr, "wrong app-name\n");
        exit(1);
    }
    for (char **p = env; p[0] != NULL; p++) {
        if (strncmp(p[0], "USER", 4)) continue;
        if (strcmp(p[0], "USER=tanxiaoze")) {
            fprintf(stderr, "wrong user-name\n");
            exit(1);
        }
    }
    printf("hello world\n");
    return 0;
}
