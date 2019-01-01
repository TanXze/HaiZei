/*************************************************************************
	> File Name: ol17.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 17时13分45秒
 ************************************************************************/

#include<stdio.h>
int num1[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int num2[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
int get_num_letters(int x){
    if(x < 20){
        return num1[x];
    }else if(x < 100){
        return num2[x / 10] + num1[x % 10];
    }else if(x < 1000){
        if(x % 100 == 0){
            return num1[x / 100] + 7;
        }else{
            return num1[x / 100] + get_num_letters(x % 100) + 10;
        }
    }else{
        return 11;
    }
}
int main(){
    int ans;
    for(int i = 0; i <= 1000; i++){
        ans += get_num_letters(i);
    }
    printf("%d", ans);
    return 0;
}
