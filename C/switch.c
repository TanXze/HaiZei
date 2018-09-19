/*************************************************************************
	> File Name: switch.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月18日 星期二 18时52分24秒
 ************************************************************************/

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1: printf("one\n"); break;
        case 2: printf("two\n"); break;
        case 3: printf("three\n"); break;
        default: printf("error\n"); break;
    }
    return 0;
}
