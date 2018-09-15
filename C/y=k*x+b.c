/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月04日 星期三 19时09分28秒
 ************************************************************************/
#include<stdio.h>
int f(int k, int b, int x){
    return k*x+b;
}
int main(){
    int k,b,x;
    scanf("%d%d", &k, &b);
    for(int i = 1;i <= 100; i++){
        printf("f(%d)=%d\n",i,f(k,b,x));
    }
    return 0;
}
