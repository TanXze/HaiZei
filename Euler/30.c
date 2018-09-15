/*************************************************************************
	> File Name: 30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 12时52分39秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int check(int i){
    int sum = 0, x = i;
    while(i){
        sum += pow(i % 10, 5);
        i /= 10;
    }
    return sum == x;
}

int main(){
    int sum = 0;
    for(int i = 2; i <= 354294; i++){
        if(check(i)){
            sum += i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
