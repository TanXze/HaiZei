/*************************************************************************
	> File Name: 3.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时37分26秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2;
    (a > b ? a : b) = 3;
    //(a > b ? a : 1) = 3;//error: lvalue required as left operand of assignment
    cout << a << " " << b << endl;
    return 0;
}
