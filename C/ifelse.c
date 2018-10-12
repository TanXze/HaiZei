/*************************************************************************
	> File Name: ifelse.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月11日 星期四 23时29分05秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d", &x);
    if (x < 10) {
        if (x >= 2) {
            y = x * x + 2 * x - 1;
        } else if (x > -5) {
            y = x * 3 - 1;
        } else if (x <= -5) {
            y = x;
        }
    } else {
        y = 0;
    }
    printf("%d\n", y);
    return 0;
}
