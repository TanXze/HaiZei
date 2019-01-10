/*************************************************************************
	> File Name: inherittest1.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 18时19分43秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Parent {
    protected:
    int i;
    public:
    Parent() {
        cout << "Parent()" << endl;
    }
    Parent (int v = 0) {
        i = v;
    }
};

class Child : public Parent {
    public:
    Child() : Parent(5) {
        cout << "Child()" << endl;
    }
    int getI() {
        return i;
    }
};

class A {
    public:
        int i;
    public:
        A() {
            cout << "A()" << endl;
        }
        A(int v) {
            i = v;
        }
        int get() { 
            cout << "A::i = " << i << endl;
            return i;
        }
        int add(int a, int b, int c) { 
            return i + a + b + c;
        }
        virtual void say() { 
            cout << "hello, i'm A." << endl;
        }
};
class B : public A {
    public:
        int i;
    public:
        B() {
            cout << "B()" << endl;
        }
        B(int v) :A(0) { 
            i = v;
        }
        int get() { 
            cout << "B::i = " << i << endl;
            return i;
        }
        int add(int a) { 
            return i + a;
        }
        int add(int a, int b) { 
            return i + a + b;
        }
        void say() { 
            cout << "hello, i'm B." << endl;
        }
};
class C {
    public:
        C() {
            cout << "C()" << endl;
        }
};
class D : public C {
    private:
        B b;
    public:
        D() {
            cout << "D()" << endl;
        }
};

void how_to_say(A *p) {
    p->say();
    return ;
}

int main() {
    Child c;
    cout << c.getI() << endl;

    D d;

    A a(2);
    B b(3);
    cout << b.i << endl; //优先使用子类的属性，父类同名属性被隐藏
    b.A::i = 5;
    cout << b.A::i << endl; //通过作用域分辨符来指定使用的是父类还是子类
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;

    cout << b.A::add(1, 2, 3) << endl;
    cout << b.get() << endl;

    how_to_say(&a);
    how_to_say(&b);
    return 0;
}
