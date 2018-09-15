/*************************************************************************
	> File Name: 34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时08分17秒
 ************************************************************************/

#include<stdio.h>

int check(int i){
    int sum = 0, x = i; 
    while(i){
        int k = 1;
        for(int j = 1; j <= i % 10; j++){
            k *= j;
        }
        sum += k;
        i /= 10;
    }
    return sum == x;
}

int main(){
    int sum = 0;
    for(int i = 3; i < 2540160; i++){
        if(check(i)){
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
