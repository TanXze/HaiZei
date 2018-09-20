/*************************************************************************
	> File Name: KR.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 18时33分27秒
 ************************************************************************/

#include <stdio.h>

int is_prime(x)
int x;
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main(){
    int x;
    scanf("%d", &x);
    int i = is_prime(x);
    printf("%d", i);
    return 0;
}
