/*************************************************************************
	> File Name: a+b.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年08月21日 星期二 10时21分25秒
 ************************************************************************/

#include <stdio.h>

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int c, d;
        while(b != 0){
            c = a ^ b;
            d = (a & b) << 1;
            a = c;
            b = d;
        }
        printf("%d\n", a);
    }
    return 0;
}
