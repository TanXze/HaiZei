/*************************************************************************
	> File Name: class_temp.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 09时35分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
class Test {
    private:
        T a;
    public:
        Test(T v) { 
            a = v;
        }
        T get() { 
            return a;
        }
        T add(T b) { 
            return a + b;
        }
        T sub(T b) { 
            return a - b;
        }
};

string operator-(const string &s1, const string &s2) {
    return "0";
}

int main() {
    Test<int> t(0);
    cout << t.get() << endl;
    cout << t.add(10) << endl;
    string s1 = "txz";
    string s2 = "haizei";
    Test<string> t1(s1);
    cout << t1.get() << endl;
    cout << t1.add(" " + s2) << endl;
    cout << t1.sub(" " + s2) << endl;
    return 0;
}
