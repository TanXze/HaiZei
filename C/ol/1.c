/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时39分43秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    int min = -1000, max = 1000, mid;
    while(min <= max){ 
        mid = (min + max) / 2;
        if(x > mid * mid * mid){
            min = mid + 1;
        }else if(x < mid * mid * mid){
            max = mid - 1;
        }else{
            printf("%d", mid);
            break;
        } 
    }
    return 0;
}
