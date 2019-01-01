/*************************************************************************
	> File Name: ol43.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月29日 星期日 09时39分48秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
#include<algorithm>
using namespace std;
int64_t check(int *a){
    int num[7] = {2, 3, 5, 7, 11, 13, 17};
    for(int i = 2, j = 0; i < 8; ++i, ++j){
        int temp_ans = a[i] * 100 + a[i + 1] * 10 + a[i + 2];
        if(temp_ans % num[j] != 0) return 0; 
    }
    int64_t sum = 0;
    for(int i =0; i < 10; i++){
        sum *= 10;
        sum += a[i];
    }
    return sum;
}
int main(){
    int a[10] = {0};
    int64_t sum = 0;
    for(int i = 0; i < 10; i++){
        a[i] = i;
    }
    do{
        sum += check(a);
    }while(next_permutation(a, a + 10));
    printf("%" PRId64 "\n", sum);
    return 0;
}
