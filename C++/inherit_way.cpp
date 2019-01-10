/*************************************************************************
	> File Name: inherit_way.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 18时05分23秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Parent {
    private:
        int a;
    public:
        int b;
        void set(int v1, int v2, int v3) {
            a = v1;
            b = v2;
            c = v3;
        }
    protected:
        int c;
};
class Child1 : public Parent {
    public:
        void print() {
            //cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
        }
};
class Child2 : private Parent {
    public:
        void print() {
            //cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
        }
};
class Child3 : protected Parent { 
    public:
        void print() {
            //cout << "a = " << a << endl;
            cout << "b = " << b << endl;
            cout << "c = " << c << endl;
        }
};

int main() {
    
    return 0;
}
