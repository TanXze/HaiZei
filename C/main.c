/*************************************************************************
	> File Name: main.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 15时48分24秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[], char *env[]) {
    for  (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    for (char **p = env; p[0] != NULL; p++) {
        printf("%s\n", p[0]);
    }
    return 0;
}
