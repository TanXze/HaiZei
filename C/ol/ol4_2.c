/*************************************************************************
	> File Name: ol4_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 20时30分43秒
 ************************************************************************/

#include<stdio.h>
int palindrome(int x){
    int temp = x, y = 0;
    while(x){
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y == temp;
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
