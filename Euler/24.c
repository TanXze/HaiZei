/*************************************************************************
	> File Name: 24.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 19时45分25秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

#define N 1000000
#define MAX_M 10

int32_t a[MAX_M] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
    int32_t n = N - 1, max = 1, ind = 0;
    while(max <= n && ind < MAX_M){
        ++ind;
        max = max * ind;
    }
    max /= ind;
    for(int32_t i = MAX_M - ind; i < MAX_M && n; i++){
        ind--;
        int32_t j = i + 1, k;
        while(n >= max && j < MAX_M){
            k = a[i];
            a[i] = a[j];
            a[j] = k;
            n -= max;
            j++;
        }
        max /= ind;
    }
    for(int32_t i = 0; i < MAX_M; i++){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
