/*************************************************************************
	> File Name: ol38.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 09时22分21秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX 10000
int isPandigital(int x, int *num){
    while(x){
        if(x % 10 == 0) return 0;
        if(num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}
int check(int x){
    int num[10] = {0};
    int temp_ans = 0;
    int value;
    for(int i = 1; ; i++){
        int t = x * i;
        if(!isPandigital(t, num)) return 0;
        value = pow(10, floor(log10(t)) + 1);
        temp_ans = temp_ans * value + t;
        int digits = floor(log10(temp_ans)) + 1;
        if(digits > 9) return 0;
        if(digits == 9) break;
    }
    return temp_ans;
}
int main(){
    int ans = 0;
    for(int i = 1; i < MAX; i++){
        int x = check(i);
        ans = ans > x ? ans : x;
    }
    printf("%d\n", ans);
    return 0;
}
