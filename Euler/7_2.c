/*************************************************************************
	> File Name: 7_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 10时22分34秒
 ************************************************************************/

#include <stdio.h>

#define MAX 150000

int main() {
    int prime[MAX + 5] = {0};
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[10001]);
    return 0;
}
