/*************************************************************************
	> File Name: while.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月18日 星期二 20时52分44秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m = 0;
    scanf("%d", &n);
    do {
        n /= 10;
        m++;
    } while(n);
    printf("%d", m);
    return 0;
}
