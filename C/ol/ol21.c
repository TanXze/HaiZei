/*************************************************************************
	> File Name: ol21.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 19时21分40秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100000

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};
int mnum[MAX + 5] = {0};

int main(){
    for(int i = 2; i <= MAX; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = i * i - 1;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i >MAX) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0){
                dnum[prime[j] * i] = dnum[i] * (mnum[i] * prime[j] + prime[j] - 1) / (mnum[i]);
                mnum[prime[j] * i] = mnum[i] * prime[j] + prime[j] - 1;
            }else{
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
                mnum[prime[j] * i] = mnum[prime[j]];
            }
        }
    }
    for(int i = 2; i <= MAX; i++){
        dnum[i] -= i;
    }
    int ans = 0;
    for(int i = 1; i <= MAX; i++){
        int a = i, b = dnum[i];
        if(a == b)
    }
}
