/*************************************************************************
	> File Name: Date.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 14时52分16秒
 ************************************************************************/

#include <stdio.h>

struct Date {
    int x = 1, y = 2;
};

int main() {
    struct Date a[2];
    int *p = a;
    printf("%d\n", a[1].x);
    return 0;
}
