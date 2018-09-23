/*************************************************************************
	> File Name: binary_search.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月23日 星期日 10时41分09秒
 ************************************************************************/

#include <stdio.h>

int binary_search(int *arr, int x, int n){
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) {
            head = mid + 1;
        }else if (arr[mid] > x) {
            tail = mid - 1;
        }else {
            return mid;
        }
    }
    return -1;
}

int main(){
    char arr[100];
    int *p1 = (int *)(arr + 1);
    int *p2 = (int *)(arr + 2);
    printf("%p %p\n", p1, p2);
    int *p3 = (int *)(arr + 1);
    int *p4 = (int *)(arr + 2);
    *p3 = 1;
    *p4 = 2;
    printf("*p3 = %d\n*p4 = %d\n", *p3, *p4);
    return 0;
}
