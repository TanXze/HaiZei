/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时50分27秒
 ************************************************************************/

#include<stdio.h>

int main(){
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= 100; i++){
        sum1 += i * i;
        sum2 += i;
    }
    int sum = sum2 * sum2;
    int x = sum - sum1;
    printf("%d\n", x);
    return 0;
}
