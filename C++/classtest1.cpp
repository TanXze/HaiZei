/*************************************************************************
	> File Name: classtest.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月01日 星期二 18时33分14秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        int i;
        int j;
    public:
        int a;
        int getI() {
            return i;
        }
        int getJ() {
            return j;
        }
        int getA() {
            return a;
        }
        void setI(int value) {
            i = value;
            return ;
        }
};

int main() {
    Test t;
    Test *t1 = new Test;
    t.a = 5;
    t1->a = 10;
    //t.i = 10;//error: ‘int Test::i’ is private within this context
    t.setI(100);
    cout << t.getI() << endl;
    cout << t.a << endl << t1->a << endl;
    delete t1;
    return 0;
}
