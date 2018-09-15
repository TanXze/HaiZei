/*************************************************************************
	> File Name: 素数筛.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 16时57分34秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100
int main(){
    int prime[105] = {0};
    for(int i = 2; i * i <= 100; i++){
        if(!prime[i]){
            for(int j = i; j <= 100; j += i){
                prime[j] = 1;
            }
        }
    }
    int n;
    while(~scanf("%d", &n)){
        printf("%s\n", prime[n] == 0 ? "yes" : "NO");
    }
    return 0;
}
