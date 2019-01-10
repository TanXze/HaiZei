/*************************************************************************
	> File Name: inherittest2.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时01分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        int i;
        int j;
    public:
        Test(int v1 = 0, int v2 = 0) { 
            i = v1;
            j = v2;
        }
        int getI() { 
            return i;
        }
        int getJ() { 
            return j;
        }
        int add(int value) {  
            return i + j + value;
        }
        ~Test() { 
            
        }
};

class A {
    int a;
    int b;
    char c;
    double d;
    public:
        void print() { 
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
            cout << "d = " << d << endl;
        }
};

struct B {
    int a;
    int b;
    char c;
    double d;
};

int main() {
    Test t(1, 3);
    cout << t.getI() << endl << t.getJ() << endl;
    cout << t.add(10) << endl;

    A a1;
    B b1;
    cout << sizeof(A) << " " << sizeof(B) << endl;
    cout << sizeof(a1) << " " << sizeof(b1) << endl; //只统计属性的大小
    a1.print();
    B *p = reinterpret_cast<B *> (&a1);
    p->a = 100;
    p->b = 1000;
    p->c = 't';
    p->d = 3.2;
    a1.print();
    p->a = 123;
    p->b = 456;
    p->c = 'x';
    p->d = 4.5;
    a1.print();
    return 0;
}
