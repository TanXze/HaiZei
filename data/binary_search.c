/*************************************************************************
	> File Name: binary_search.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年11月06日 星期二 19时27分09秒
 ************************************************************************/

#include <stdio.h>

#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

//12345678
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//111111000000最后一个1的位置
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000001111111第一个1的位置
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int num1[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int num2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int num3[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    P(binary_search1(num1, 10, 11));
    P(binary_search2(num2, 10));
    P(binary_search3(num3, 10));
    return 0;
}
