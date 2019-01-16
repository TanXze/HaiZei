/*************************************************************************
	> File Name: inherit_sizeof.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 10时23分35秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    protected:
        int i;
        int j;
    public:
        A(int v1, int v2) { 
            i = v1;
            j = v2;
        }
        virtual void print() { 
            cout << "hello haizei" << endl;
        }
};

class B : public A {
    private:
        int k;
    public:
        B(int v1, int v2, int v3) : A(v1, v2){ 
            i = v1;
            j = v2;
            k = v3;
        }
        void show() { 
            cout << "i = " << i << endl;
            cout << "j = " << j << endl;
            cout << "k = " << k << endl;
        }
};

typedef struct C {
    void *p;
    int a;
    int b;
    int c;
} C;

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;

    B b(1, 2, 3);
    b.show();
    C *p = reinterpret_cast<C*>(&b);
    p->a = 10;
    p->b = 100;
    p->c = 1000;
    b.show();
    return 0;
}
