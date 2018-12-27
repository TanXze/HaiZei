/*************************************************************************
	> File Name: ol46.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 11时31分42秒
 ************************************************************************/

#include<stdio.h>
#define MAX 1000000

int prime[MAX + 5] = {0};
int ans[MAX + 5] = {0};

void Prime(){
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i <= MAX; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++){
            if(i * prime[j] > MAX) break;
            ans[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int main(){
    Prime();
    for(int i = 9; i <= MAX; i += 2){
        int flag = 0;
        if(ans[i] == 0) continue;
        for(int j = 1; j * j * 2 < i; j++){
            int temp;
                temp = i - j * j * 2;
                if(ans[temp] == 0){
                    flag = 1;
                    break;
                }
        }
        if(flag == 0){
            printf("%d\n", i);
            break;
        };
    }
    return 0;
}
