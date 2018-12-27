/*************************************************************************
	> File Name: 5.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 19时37分35秒
 ************************************************************************/

#include <iostream>
using namespace std;

//函数占位参数，只有类型，没有形参
void f(int a, int) {
    cout << "hello" << endl;
}

void g(int = 0, int = 0, int = 0) {//默认值占位
    cout << "world" << endl;
}

int main() {
    //f();// error: too few arguments to function ‘void f(int, int)’
    f(1, 2);
    g();
    g(1, 2, 3);
    return 0;
}
