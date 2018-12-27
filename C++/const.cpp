/*************************************************************************
	> File Name: 1.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月27日 星期四 18时17分16秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    const int a = 5;
    int *p = (int *)&a;
    *p = 6;
    printf("%d %d\n", a, *p);
    return 0;
}
