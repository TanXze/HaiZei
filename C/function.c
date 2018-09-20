/*************************************************************************
	> File Name: function.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 19时47分55秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x);

int main(){
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    return 0;
}
