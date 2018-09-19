/*************************************************************************
	> File Name: if.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月18日 星期二 18时29分28秒
 ************************************************************************/

#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) != EOF) { 
        if (n < 0) {
            printf("ERROR");
        } else if (n == 0) {
            printf("FOOLISH");
        } else if (n < 60) {
            printf("FAIL");
        } else if (n < 75) {
            printf("MEDIUN");
        } else if (n <= 100) {
            printf("GOOD");
        }
    }
    return 0;
}
