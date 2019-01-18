/*************************************************************************
	> File Name: exception.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 14时13分52秒
 ************************************************************************/

#include <stdio.h>

int div(int a, int b) {
    if (b != 0)
        return a / b;
    else 
        return 0;
}

int main() {
    printf("%d\n", div(1, 1));
    printf("%d\n", div(1, 0));
    printf("%d\n", div(0, 10));
    return 0;
}
