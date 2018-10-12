/*************************************************************************
	> File Name: 0-A.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月11日 星期四 22时54分08秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x >= 0 && x <= 25) {
        putchar(x + 'A');
        printf("\n");
    } else if (x >= 26 && x <= 51) {
        x -= 26;
        putchar(x + 'a');
        printf("\n");
    }
    return 0;
}
