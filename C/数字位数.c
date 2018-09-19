/*************************************************************************
	> File Name: c1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月13日 星期四 18时29分54秒
 ************************************************************************/

#include <stdio.h>

int main(){
    int a;
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    scanf("%d",&a);
    printf(" has %d dights\n", printf("%d", a));   //printf
    printf("%d\n", sprintf(str, "%d", a));    //sprintf
    for(int i = 1, j = 0; i <= 20; i++) {
        j += sprintf(str + j, "%d", i);
    }
    printf("str = %s\n", str);
    printf("%d\n", fprintf(fout, "%d", a));   //fprintf
    return 0;
}
