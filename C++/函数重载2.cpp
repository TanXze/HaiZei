/*************************************************************************
	> File Name: 1.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 20时18分14秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace my_lib{
    int add(int x, int y = 5) {
        return x + y;
    }
    int add() {
        return 100;
    }

    string add(string &s1, string &s2) {
        return s1 + s2;
    }
}

using namespace my_lib;

int (*p1)(int, int);
int (*p2)();

int main() {
    string s1 = "txz", s2 = "haizei";
    p1 = add;
    p2 = add;
    int c = (*p1)(1, 2);
    int d = (*p2)();
    cout << c << endl;
    cout << d << endl;
    cout << add() << endl;
    cout << add(1, 2) << endl;
    cout << add(s1, s2) << endl;
    printf("%p %p\n", p1, p2);
    return 0;
}
