/*************************************************************************
	> File Name: 10.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时14分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#define MAX 2000000

int64_t prime[MAX + 5] = {0};

int main(){
    int64_t sum = 0;
    for(int64_t i = 2; i <= MAX; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            sum += i;
        }
        for(int64_t j = 1; j <= prime[0] && i * prime[j] <= MAX; j++){
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
