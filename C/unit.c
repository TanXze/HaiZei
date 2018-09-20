/*************************************************************************
	> File Name: is_prime.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 19时56分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    } 
    return 1;
}

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int temp = va_arg(arg, int);
        ans = temp > ans ? temp : ans;
    }
    return ans;
}

