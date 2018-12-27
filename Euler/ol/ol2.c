/*************************************************************************
	> File Name: ol2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 11时59分26秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int32_t main(){
    int a = 1, b = 1, c;
    int sum = 0;
    while(b < 4000000){
        if(b % 2 == 0) sum += b;
        c = b;
        b = a + b;
        a = c;
    }
    printf("%d\n", sum);
    return 0;
}
