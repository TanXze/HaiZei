/*************************************************************************
	> File Name: master.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月13日 星期二 19时50分09秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    /*for (int i = 0; i < 5; i++) {
        if ((pid = fork()) == 0) {
            printf("Child\n");
            return 0;
        }
        sleep(1);
    }*/
    int n, x, y;
    scanf("%d", &n);
    x = n % 5;
    if (x != 0) {
        y = n / 5 + 1;
    } else {
        y = n / 5;
    }
        for (int i = 0; i < 5; i++) {
            pid = fork();
            if (pid == 0 || pid == -1) break;
            n -= 2;
        }
        if (pid == -1) {
            printf("Fork() Error\n");
        } else if (pid == 0) {
            for (int j = 0; j < y; j++) { 
                printf("Pi%d\n", n--);
            }
            close();
        }
    return 0;
}
