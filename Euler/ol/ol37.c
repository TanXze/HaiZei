/*************************************************************************
	> File Name: ol37.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月25日 星期三 19时48分58秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 2000000

int prime[MAX+5] = {0};
int prime_num[MAX] = {0};

int kejie(int x){
    int digits = floor(log10(x));
    int digits_value = pow(10, digits);
    int temp = x;
    if(digits >= 1){
        for(int i = 0; i < digits; i++){
            x = x % digits_value;
            if(prime[x] == 1) return 0;
            digits_value = digits_value / 10;
        }
        for(int i = 0; i < digits; i++){
            temp = temp / 10;
            if(prime[temp] == 1) return 0;
        }
        return 1;
    }
    return 0;
}

int main(){
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i < MAX; i++){
        if(!prime[i]) prime_num[++prime_num[0]] = i;
        for(int j = 1; j <= prime_num[0]; j++){
            if(i * prime_num[j] > MAX) break;
            prime[i * prime_num[j]] = 1;
            if(i % prime_num[j] == 0) break;                 
        }                    
    }
    int sum = 0;
    for(int i = 1; i <= prime_num[0]; i++){
        if(kejie(prime_num[i])){
            sum += prime_num[i];
            printf("%d\t", prime_num[i]);
        }        
    }
    printf("\n%d", sum);
    return 0;

}
