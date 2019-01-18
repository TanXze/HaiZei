/*************************************************************************
	> File Name: friend.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 16时06分32秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        int i;
    public:
        Test(int v = 0) { 
            i = v;
        }
        friend int get(Test &t);
};

int get(Test &t) {
    return t.i;
}

class C {
    private:
        int c;
    public:
        C(int v = 0) { 
            c = v;
        }
    friend class B;
};

class B {
    private:
        int b;
    public:
        B(int v = 0) { 
            b = v;
        }
        int getC(C &c1) { 
            return c1.c;
        }
        friend class A;
};

class A {
    public:
        int getB(B &b1) { 
            return b1.b;
        }
        //友元只是单向传递，ab是朋友，bc是朋友，ac不是朋友
        /*int getC(C &c1) { 
            return c1.c;
        }*/
};

int main() {
    Test t(10);
    cout << get(t) << endl;

    C c(10);
    B b(5);
    A a;
    cout << a.getB(b) << endl;
    cout << b.getC(c) << endl;
    return 0;
}
