/*************************************************************************
	> File Name: ol35.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 18时38分42秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 1000000

int prime[MAX+5] = {0};
int prime_num[MAX] = {0};

int yuanzhou(int x){
    int digits = floor(log10(x));
    int digits_value = pow(10, digits);
    for(int i = 0; i < digits; i++){
        int temp = x / digits_value;
        x = (x % digits_value) * 10 + temp;
        if(prime[x] == 1) return 0;
    }
    return 1;
}

int main(){
    for(int i = 2; i <= MAX; i++){
        if(!prime[i]) prime_num[++prime_num[0]] = i;
        for(int j = 1; j <= prime_num[0]; j++){
            if(i * prime_num[j] > MAX)break;
            prime[i * prime_num[j]] = 1;
            if(i % prime_num[j] == 0) break;        
        }        
    }
    int num = 0;
    for(int i = 1; i <= prime_num[0]; i++){
        if(yuanzhou(prime_num[i])){
            num++;
            printf("%d\t",prime_num[i]);
        }
    }
    printf("%d", num);
    return 0;
}
