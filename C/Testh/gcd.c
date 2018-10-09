/*************************************************************************
	> File Name: gcd.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时25分09秒
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
