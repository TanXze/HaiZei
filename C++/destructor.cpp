/*************************************************************************
	> File Name: destructor.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 18时48分01秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Value {
    private:
        int i;
    public:
        Value(int v):i(v) {
            cout << "Value() " << i << endl;
        }
};

class Test {
    private:
        Value v1;
        Value v2;
    public:
        Test(): v1(1), v2(2){
            cout << "hello" << endl;
        }
        //析构函数
        ~Test() {
            cout << "bye" << endl;
        }
};

int main() {
    Test t;
    Test *p = new Test;
    delete p;
    return 0;
}
