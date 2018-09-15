/*************************************************************************
	> File Name: ol14.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 16时20分16秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 1000000
#define KEEP 1000000

int keep[KEEP + 5] = {0};

int64_t f(int64_t x){
    if(x == 1)return 1;
    if(x <= KEEP && keep[x]) return keep[x];
    int ans;
    if(x & 1){
        ans = f(3 * x + 1) + 1;
    }else{
        ans = f(x >> 1) + 1;
    }
    if(x <= KEEP) keep[x] = ans;
    return ans;
}

int main(){
    int max_length = 0, ans_num = -1;
    for(int i = 1; i <= MAX; i++){
        int temp  = f(i);
        if(temp > max_length){
            ans_num = i;
            max_length = temp;
        }
    }
    printf("%d\n", ans_num);
    return 0;
}
