/*************************************************************************
	> File Name: struct.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月08日 星期二 18时10分08秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    //private
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};

struct B {
    //public
    int a;
    int b;
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
};

int main() {
    A aa;
    B bb;
    aa.a = 10;
    aa.b = 100;
    cout << aa.getA() << endl;
    cout << aa.getB() << endl;
    bb.a = 100;
    bb.b = 10;
    cout << bb.getA() << endl;
    cout << bb.getB() << endl;
    return 0;
}
