/*************************************************************************
	> File Name: classoperate.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月01日 星期二 18时45分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Operate {
    public:
    double q(double a, double b) {
        return a + b;
    }
    double w(double a, double b) {
        return a - b;
    }
    double e(double a, double b) {
        return a * b;
    }
    double r(double a, double b) {
        if (b == 0) {
            cout << "false" << endl;
        } else {
            return a / b;
        }
    }
};

int main() {
    Operate o;
    double a, b;
    char c;
    cin >> a >> c >> b;
    switch (c) {
        case '+':
            cout << o.q(a, b) << endl; break;
        case '-':
            cout << o.w(a, b) << endl; break;
        case '*':
            cout << o.e(a, b) << endl; break;
        case '/':
            cout << o.r(a, b) << endl; break;
        default:
            cout << "false" << endl; break;
    }
    return 0;
}
