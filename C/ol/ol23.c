/*************************************************************************
	> File Name: ol23.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 19时46分07秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAX 28123

int prime[MAX + 5] = {0};
int dnum[MAX + 5] = {0};
int mnum[MAX + 5] = {0};
int arr[MAX + 5] = {0};

int main(){
    for(int i = 2; i <= MAX; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = i * i - 1;
        }
        for(int j = 1; j<= prime[0]; j++){
            if(prime[j] * i > MAX) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j]){
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
                mnum[prime[j] * i] = mnum[prime[j]];
            }else{
                dnum[prime[j] * i] = dnum[i] * (mnum[i] * prime[j] + prime[j] - 1) / mnum[i];
                mnum[prime[j] * i] = mnum[i] * prime[j] + prime[j] - 1;
                break;
            }
        } 
    }
    for(int i = 2; i <= MAX; i++){
        dnum[i] -= i;
        if(dnum[i] > i){
            arr[++arr[0]] = i;
        }
    }
    memset(prime, 0, sizeof(prime));
    for(int i = 1; i <= arr[0]; i++){
        for(int j = i; j <= arr[0]; j++){
            if(arr[i] + arr[j] > MAX) break;
            prime[arr[i] + arr[j]] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i <= MAX; i++){
        if(!prime[i]) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
