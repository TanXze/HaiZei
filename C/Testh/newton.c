/*************************************************************************
	> File Name: newton.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时44分39秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double f(double x) {
    return 2 * x * x * x  - 4 * x * x + 3 * x - 6;
}

double f_prime(double x) {
    return 6 * x * x - 8 * x + 3;
}

double newton(double x) {
    while (fabs(f(x)) > EPSILON) {
        x -= f(x) / f_prime(x);
    }
    return x;
}
