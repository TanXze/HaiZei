/*************************************************************************
	> File Name: order.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 19时39分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Value {
    public:
    Value() {
        cout << "1" << endl;
    }
    ~Value() {
        cout << "~1" << endl;
    }
};

class Test {
    private:
        Value v1;
        Value v2;
    public:
    Test() {
        cout << "2" << endl;
    }
    ~Test() {
        cout << "~2" << endl;
    }
};

int main() {
    Test t;
    return 0;
}
