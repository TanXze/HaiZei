/*************************************************************************
	> File Name: 1.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时27分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

void f() {
    #define N 100
    const int A = 100;
}

void g() {
    //printf("%d %d\n", N, A);//error: ‘A’ was not declared in this scope
    printf("%d\n", N);
}

int main() {
    g();
    return 0;
}
