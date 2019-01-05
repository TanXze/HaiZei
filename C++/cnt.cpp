/*************************************************************************
	> File Name: cnt.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 19时56分06秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        static int cnt;
    public:
    Test() {
        cnt += 1;
    }
    static int getCnt() {
        return cnt;
    }
    ~Test() {
        cnt -= 1;
    }
};

int Test::cnt = 0;
int main() {
    cout << Test::getCnt() << endl;
    Test t1;
    Test t2;
    cout << Test::getCnt() << endl;
    cout << Test::getCnt() << endl;
    Test t3;
    cout << Test::getCnt() << endl;
    Test t4;
    cout << Test::getCnt() << endl;
    Test *p = new Test;
    cout << Test::getCnt() << endl;
    delete p;
    cout << Test::getCnt() << endl;
    return 0;
}
