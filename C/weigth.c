/*************************************************************************
	> File Name: weigth.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月11日 星期四 23时22分43秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d", &x);
    if (x > 20) {
        if (x <= 40) {
            y = (x - 20) * 2;
        } else if (x <= 50) {
            y = (x - 40) * 5 + 20 * 2;
        } else {
            y = (x - 50) * 10 + 10 * 5 + 20 * 2;
        }
    } else if (x > 0) {
        y = 0;
    }
    printf("%d\n", y);
    return 0;
}
