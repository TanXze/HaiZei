/*************************************************************************
	> File Name: revtest.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月08日 星期二 18时16分28秒
 ************************************************************************/

//g++ revtest.cpp -fno-elide-constructors

#include <iostream>
using namespace std;

class Test {
    private:
        int i;
    public:
        Test(int v) { 
            i = v;
            cout << "Test(int v): i = " << i << endl;
        }
        Test() { 
            i = 0;
            cout << "Test(): i = " << i << endl;
            //Test(100); //手动调用构造函数，产生临时对象
        }
        Test(const Test &t) {
             i = t.i;
            cout << "Test(const Test &t): i = " << i << endl;
        }
        void printI() { 
            cout << "i = " << i << endl;
        }
};

void func1(Test t) {
    return ;
}

Test func2() {
    Test t(100);
    return t;
    //return Test(100); //等价
}

int main() {
    //Test t; //调用无参构造函数
    //t.printI();
    Test t = Test(100);
    t.printI();
    func1(t);
    Test t1 = func2();
    t1.printI();
    Test t2[3] = {Test(1), Test(2), Test(3)};
    Test t3[3] = {1, 2, 3};
    return 0;
}
