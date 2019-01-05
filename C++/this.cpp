/*************************************************************************
	> File Name: this.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 20时33分27秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        static int cnt;
        int m;
    public:
        static int getCnt(Test &t, int v) {
            t.m = v;
            return cnt;
        }
        Test() {
            m = 1;
            cnt += 1;
        }
        ~Test() {
            cnt -= 1;
        }
        Test *getP() {
            return this;
        }
        int getM(){
            return this->m;
        }
};

int Test::cnt = 0;
int main() {
    Test t;
    cout << Test::getCnt(t, 5) << endl;
    printf("&t = %p\n", &t);
    printf("this = %p\n", t.getP());
    cout << t.getM() << endl;
    return 0;
}
