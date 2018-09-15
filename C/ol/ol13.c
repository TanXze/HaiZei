/*************************************************************************
	> File Name: ol13.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 18时42分44秒
 ************************************************************************/

#include<stdio.h>
#define BASE 10
int main(){
    int sum[55] = {0};
    char a[55];
    sum[0] = 50;
    while(~scanf("%s", a)){
        int i = 49;
        while(i >= 0){
            sum[50 - i] += a[i] - '0';
            i--;
        }
    }
    for(int i = 1; i <= sum[0]; i++){
        if(sum[i] < BASE)continue;
        sum[i + 1] += sum[i] / BASE;
        sum[i] %= BASE;
        sum[0] += (i == sum[0]);
    }
    int ans = 0;
    for(int i = sum[0]; i > sum[0] - 10; i--)
    printf("%d", sum[i]);
    return 0;
}
