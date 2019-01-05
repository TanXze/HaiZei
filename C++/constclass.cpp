/*************************************************************************
	> File Name: const.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月03日 星期四 20时41分04秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test{
    private:
        int i;
        int j;
        const int m;
    public:
    Test(int v):m(10) {
            this->i = v;
            this->j = 5;
        }
        int getI() const{
            cout << "const" << endl;
            return this->i;
        }
        int getI() {
            cout << "normal" << endl;
            return this->i;
        }
        int getJ() {
            return this->j;
        }
        int getM() {
            return this->m;
        }
        void setM(int v) {
            int *p = const_cast<int *>(&m);
            *p = v;
            return ;
        }
};

int main() {
    Test t(1);
    cout << t.getI() << endl;
    cout << t.getM() << endl;
    t.setM(100);
    cout << t.getM() << endl;
    //cout << t.getJ() << endl;//error: passing ‘const Test’ as ‘this’ argument discards qualifiers [-fpermissive]
    return 0;
}
