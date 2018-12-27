/*************************************************************************
	> File Name: swap.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时50分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

void swap_1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

void swap_2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return ;
}

int f() {
    int a = 4;
    int &b = a;
    return b;
}

int main() {
    int a = 5, b = 6;
    cout << a << " " << b << endl;
    swap_1(&a, &b);
    cout << a << " " << b << endl;
    swap_2(a, b);
    cout << a << " " << b << endl;
    int c = 1;
    c = f();
    cout << c << endl;
    return 0;
}
