/*************************************************************************
	> File Name: ol12.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 15时48分16秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};

void init(){
    for(int i = 2; i <= MAX_N; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 2;
        }
        for(int j = 1; j <= prime[0]; j++){
            if(prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0){
                int knum = 0, pre_i = i;
                while(pre_i % prime[j] == 0) pre_i /= prime[j], knum++;
                dnum[prime[j] * i] = dnum[i] / (knum + 1) * (knum + 2);
                break;
            }else{
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            }
        }
    }
    return ;
}

int main(){
    init();
    int n = 2;
    while(1){
        int total_factors = 0;
        if(n & 1){
            total_factors = dnum[n] * dnum[(n + 1) >> 1];
        }else{
            total_factors = dnum[n >> 1] + dnum[n + 1];
        }
        if(total_factors >= 500) break;
        ++n;
    }
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
