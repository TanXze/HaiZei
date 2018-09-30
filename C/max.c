/*************************************************************************
	> File Name: max.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月23日 星期日 16时46分19秒
 ************************************************************************/

#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b) {
        if (a >= c) {
            printf("%d\n", a);
        } else {
            printf("%d\n", c);
        } 
    } else {
        if (b >= c) {
            printf("%d\n", b);
        } else {
            printf("%d\n", c);
        }
    } 
    return 0;
}
