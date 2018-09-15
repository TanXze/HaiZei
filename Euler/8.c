/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 15时52分31秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include "8.h"

int main(){
    int64_t p = 1;
    int64_t P = 0;
    int zero = 0;
    for(int i = 0; i < 1000; i++){
        if(i < 13){
            if(str[i] == '0'){
                zero++;
            }else{
                p *= str[i] - '0';
            }
        }else{
            if((str[i] - '0') != 0){
                p *= str[i] - '0';
            }else{
                zero++;
            }
            if((str[i - 13] - '0') != 0){
                p /= str[i - 13] - '0';
            }else{
                zero--;
            }
            if(p > P && !zero){
                P = p;
            }
        }
    }
    printf("%ld\n", P);
    return 0;
}
