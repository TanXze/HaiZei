/*************************************************************************
	> File Name: ol2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月15日 星期日 11时59分22秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 400000
int main(){
    int prime[MAX] = {0};
    for(int i = 2; i <= MAX; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] > MAX)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[20000]);
    return 0;
}
