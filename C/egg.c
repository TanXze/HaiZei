/*************************************************************************
	> File Name: egg.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月11日 星期四 23时09分12秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if (x < 5) {
        printf("10\n");
    } else if (x >= 5 && x < 10) {
        printf("12\n");
    } else if (x >= 10 && x < 20) {
        printf("15\n");
    } else if (x >= 20 && x < 30) {
        printf("18\n");
    } else if (x >= 30) {
        printf("20\n");
    }
    return 0;
}
