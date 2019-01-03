/*************************************************************************
	> File Name: const.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时10分35秒
 ************************************************************************/

#include <stdio.h>

int main() {
    const int a = 5;
    int *p = (int *)&a;
    *p = 6;
    printf("%d %d\n", a, *p);
    return 0;
}
