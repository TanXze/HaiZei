/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 18时56分18秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int money[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int d[205] = {0};
int main(){
    d[0] = 1;
    for(int32_t i = 0; i < 8; i++){
        for(int32_t j = 0; j <= 200 - money[i]; j++){
            d[j + money[i]] += d[j];
        }
    }
    printf("%d\n", d[200]);
    return 0;
}
