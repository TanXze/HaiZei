/*************************************************************************
	> File Name: is_prime.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 19时56分13秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    } 
    return 1;
}

