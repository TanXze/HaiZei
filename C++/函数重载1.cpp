/*************************************************************************
	> File Name: 1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 19时57分11秒
 ************************************************************************/

#include <iostream>
using namespace std;

int add() {
    return 4;
}

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int a = 2, b = 3, c = 4;
    printf("%d\n", add());
    printf("%d\n", add(a, b));
    printf("%d\n", add(a, b, c));
    return 0;
}
