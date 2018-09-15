/*************************************************************************
	> File Name: ol4.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 18时45分46秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int palindrome(int x){
    int digits = floor(log10(x));
    int temp = x;
    int y = 0;
    for(int i = 0; i <= digits + 1; i++){
        y += (x % 10) * pow(10, digits - i);
        x /= 10;
    }
    if(y == temp) return true;
    else return false;
}

int main(){
    int MAX_palindrome = 0;
    for(int i = 100; i <= 999; i++){
        for(int j = i; j <= 999; j++){
            if(palindrome(i * j) && i * j > MAX_palindrome){
                MAX_palindrome = i * j;
                break;
            }
        }
    }
    printf("%d\n", MAX_palindrome);
    return 0;
}
