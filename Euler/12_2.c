/*************************************************************************
	> File Name: 12_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 11时28分01秒
 ************************************************************************/

#include <stdio.h>

#define MAX 100000

int mnum[MAX + 5] = {0};
int dnum[MAX + 5] = {0};
int prime[MAX + 5] = {0};

int main() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            } else {
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
    printf("%d\n", dnum[28]);
}
