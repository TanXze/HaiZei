/*************************************************************************
	> File Name: lesson_init.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 18时11分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Value {
    private:
        int i;
    public:
        Value(int v):i(v) {
            cout << "value::i = " << i << endl;
        }
};

class Test {
    private:
        const int i;
        int a;
        Value v1;
    public:
        Test (int v1, int v2);
        int getI() {
            return i;
        }
};

Test::Test(int v1, int v2):i(v1), a(v2), v1(1){
    cout << "i = " << i << endl;
    cout << "a = " << a << endl;
}

int main() {
    Test t1(5, 8);
    return 0;
}
