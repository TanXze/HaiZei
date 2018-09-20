/*************************************************************************
	> File Name: function.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 19时47分55秒
 ************************************************************************/

#include <stdio.h>

#define P(func){ \
    printf("%s = %d\n", #func, func); \
}

int is_prime(int x);
int max_int(int n, ...);

int main(){
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    P(max_int(3, 1, 2, 3));
    P(max_int(4, 5, 6, 7, 8));
    P(max_int(5, 6, 14, 8, 9, 10));
    return 0;
}
