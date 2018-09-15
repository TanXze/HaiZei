/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月04日 星期三 19时16分57秒
 ************************************************************************/

#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    swap(&a,&b);
    printf("a=%d\nb=%d\n",a,b);
    return 0;
}
