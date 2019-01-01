/*************************************************************************
	> File Name: ol8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 14时35分21秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "1.h"
int main(){
    int64_t P = 1;
    int64_t Pmax = 0;
    int zero = 0;
    for(int i = 0; i < 1000; i++){
        if(i < 13){
            if(str[i] == '0'){
                zero++;
            } else {
                P *= str[i] - '0';
            } 
        } else if(i >= 13){
            if((str[i] - '0') != 0){
                P *= str[i] - '0';
            }else{
                zero++;
            }
            if((str[i - 13] - '0') != 0){
                P /= str[i - 13] - '0';
            }else{
                zero--;
            }
            if(P > Pmax && !zero){
                Pmax = P;
            }
        }
    }
    printf("%ld", Pmax);
    return 0;
}
