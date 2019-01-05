/*************************************************************************
	> File Name: classtest2.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月01日 星期二 19时22分25秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        int a;
        int *p;
    public:
        int getA() {
            return a;
        }
        int* getP() {
            return p;
        }
        //构造函数
        Test() {
            a = 10;
            cout << "Test()" << endl;
        }
        //可重载
        Test(int value) {
            a = value;
            cout << "Test(int)" << endl;
        }
};

Test t1;
int main() {
    cout << "t1:" << t1.getA() << endl;
    Test t2(3);
    cout << "t2:" << t2.getA() << endl;
    Test t3 = 100;//兼容C语言
    cout << "t3:" << t3.getA() << " &t3:" << t3.getP() << endl;
    Test t4 = t3;//简单的值复制
    cout << "t4:" << t4.getA() << " &t4:" << t4.getP() << endl;
    Test *q = new Test(8);
    cout << "q:" << q->getA() << endl;
    //手动调用构造函数
    Test t[3] = {Test(), Test(4), Test(5)};
    for (int i = 0; i < 3; i++) {
        cout << t[i].getA() << endl;
    }
    delete q;
    return 0;
}
