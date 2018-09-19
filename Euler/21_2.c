/*************************************************************************
	> File Name: 21_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 23时09分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>

#define MAX_N 10000

int32_t isPrime[MAX_N + 5] = {0};
int32_t prime[MAX_N] = {0};
int32_t d[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) {
            isPrime[i] = i;
            d[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * (isPrime[i] * prime[j] * prime[j] - 1) / (isPrime[i] * prime[j] - 1);
                break;
            } else {
                isPrime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[i] * d[prime[j]];
            }
        }
    }
    printf("%d\n", d[12]);
    return 0;
}
