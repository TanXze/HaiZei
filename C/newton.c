/*************************************************************************
	> File Name: newton.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月09日 星期二 11时38分30秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

double f(double x) {
    return 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
}

double f_prime(double x) {
    return 6 * pow(x, 2) - 8 * x + 3;
}

double newton(double (*fp)(double), double (*fp_prime)(double)) {
    double x = 1.5;
    while(fabs(fp(x)) > EPSILON) {
        x -= fp(x) / fp_prime(x);
    }
    return x;
}

int main() {
    printf("%g\n", newton(f, f_prime));
    return 0;
}
