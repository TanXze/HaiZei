/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时34分50秒
 ************************************************************************/

#include<stdio.h>

int check(int a){
    int b = a, x = 0;
    while(a){
        x = x * 10 + a % 10;
        a /= 10;
    }
    return b == x;
}

int main(){
    int max = 0;
    for(int i = 100; i < 1000; i++){
        for(int j = i; j < 1000; j++){
            if(check(i * j) && i * j > max){
                max = i * j;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
