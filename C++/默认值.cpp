/*************************************************************************
	> File Name: 2.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 19时15分53秒
 ************************************************************************/

#include <iostream>
using namespace std;

int add(int a = 2, int b = 3, int c = 4);

int main() {
    cout << add() << endl; //默认值
    cout << add(1) << endl; //优先从左往右
    cout << add(1, 2) << endl;
    return 0;
}

int add(int a, int b, int c) {
    return a + b + c;
}
