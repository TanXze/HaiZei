/*************************************************************************
	> File Name: ol44.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 10时31分24秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int getValue(int n){
    return (n * (n * 3 - 1)) / 2;
}
int isPentagonal(int64_t x){
    int min = 0, max = x, mid;
    while(min <= max){
        int temp;
        mid = (min + max) / 2;
        if((temp = getValue(mid)) == x) break;
        if(x < temp){
            max = mid - 1;
        }else{
            min = mid + 1;
        }
    }
    if(min > max) return 0;
    return mid;
}
int isPandigital(int D){
    int ans;
    for(int j = 1; ; j++){
        for(int k = j - 1; j > 0; j--){
            D = getValue(j) - getValue(k);
            if(isPentagonal(D)){
                ans = ans < D ? ans : D;
                return ans;
            }
        }
    }
}
int main(){
    printf("%d\n", isPandigital);
    return 0;
}
