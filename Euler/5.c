/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时16分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}

int main(){
    int ans = 1;
    for(int i = 1; i <= 20; i++){
        ans *= i / gcd(i, ans);
    }
    printf("%d\n", ans);
    return 0;
}
