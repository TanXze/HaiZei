/*************************************************************************
	> File Name: 2.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时34分00秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int a = 5;
    bool b = false;
    cout << a << " " << b << endl;
    b++;
    cout << a << " " << b << endl;
    a = b + a;
    cout << a << " " << b << endl;
    return 0;
}
