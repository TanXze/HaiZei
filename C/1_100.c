/*************************************************************************
	> File Name: 1_100.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月02日 星期三 19时09分33秒
 ************************************************************************/

#include<stdio.h>
int main(){
    static int num = 1;
    printf("%d\n", num);
    if(num == 100) return 0;
    num++;
    return main();
}
