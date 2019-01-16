/*************************************************************************
	> File Name: inherit_more.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 14时50分13秒
 ************************************************************************/

#include <iostream>
using namespace std;

class BaseA {
    public:
        virtual void funcA() { 
            cout << "BaseA::funcA" << endl;
        }
};

class BaseB {
    public:
        virtual void funcB() {
            cout << "BaseB::funcB" << endl;
        }
};

class Derived : public BaseA, public BaseB {
    
};

int main() {
    cout << sizeof(Derived) << endl;
    Derived d;
    BaseA *p1 = &d;
    BaseB *p2 = &d;
    p1->funcA();
    p2->funcB();
    BaseB *pb = (BaseB *)p1;
    pb->funcB();
    BaseB *pbb = dynamic_cast<BaseB*>(p1);
    pbb->funcB();
    return 0;
}
