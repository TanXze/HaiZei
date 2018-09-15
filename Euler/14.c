/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时40分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

#define MAX_KEEP_RANGE 50000000
#define MAX_N 1000000

int32_t skeep[MAX_KEEP_RANGE + 5] = {0};

int32_t KeepChainLength(int64_t x){
    if(x == 1) return 1;
    if(x <= MAX_KEEP_RANGE && skeep[x] != 0) return skeep[x];
    int32_t ans;
    switch(x % 2){
        case 0:ans = KeepChainLength(x >> 1) + 1; break;
        case 1:ans = KeepChainLength(3 * x + 1) + 1; break;
    }
    if(x <= MAX_KEEP_RANGE) skeep[x] = ans;
    return ans;
}

int main(){
    int32_t maxi = 1;
    for(int32_t i = 2; i <= MAX_N; ++i){
        if(KeepChainLength(i) > KeepChainLength(maxi)){
            maxi = i;
        }
    }
    printf("%d(chain length:%d)\n", maxi, KeepChainLength(maxi));
    return 0;
}
