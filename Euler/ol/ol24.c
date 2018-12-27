/*************************************************************************
	> File Name: ol24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 19时55分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int NUM, k;

int get_num(int n, int *num, int delta){
    int rank = n / delta + 1, now = 0;
    for(int i = 0; i < NUM; i++){
        now += !(num[i]);
        if(now == rank) return i;
    }
    return -1;
}
int main(){
    scanf("%d %d", &NUM, &k);
    int m = 1;
    for(int i = 1; i <= NUM - 1; i++){
        m *= i;
    }
    int n = k - 1, delta = m;
    int *num = (int *)malloc(sizeof(int)*NUM);
    for(int i = 0; i < NUM; i++){
        int digit = get_num(n, num, delta);
        printf("%d", digit);
        num[digit] = 1;
        n %= delta;
        if(i == NUM - 1) break;
        delta /= (NUM - 1 - i);
    }
    return 0;
}
