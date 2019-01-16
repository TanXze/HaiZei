/*************************************************************************
	> File Name: duotai.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 09时29分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Parent {
    public:
        virtual void say() { 
            cout << "I'm Parent" << endl;
        }
};

class Child : public Parent {
    public:
        void say() { 
            cout << "I'm Child" << endl;
        }
};

void how_to_say(Parent *p) {
    p->say();
}

int main() {
    Parent p;
    Child c;
    how_to_say(&p);
    how_to_say(&c);
    return 0;
}
