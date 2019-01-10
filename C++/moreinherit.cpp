/*************************************************************************
	> File Name: inherittest3.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时49分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    private:
        string name;
        int age;
    public:
        void print() { 
            cout << name << "  " << age << endl;
        }
};
class B : public A {};
class C : public A {};
class D : public B, public C {}; //多继承

int main() {
    D d;
    B *pb = &d;
    C *pc = &d;
    void *pbb = pb;
    void *pcc = pc;
    if (pbb == pcc) {
        cout << "Point the same address!" << endl;
    } else {
        cout << "No!" << endl;
    }
    cout << pb << "  " << pbb << endl;
    cout << pc << "  " << pcc << endl;
    cout << &d << endl; //先继承B,与B的地址相同
    d.B::print();
    d.C::print();
    return 0;
}
