/*************************************************************************
	> File Name: newton_sqrt.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月09日 星期二 16时02分59秒
 ************************************************************************/

#include <stdio.h>

double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return 2 * x;
}

double newton(double x0, double n, double (*fp)(double, double), double (*fp_prime)(double)) {
    double x = x0;
    #define EPS 1e-7
    x -= fp(x, n) / fp_prime(x);
    x -= fp(x, n) / fp_prime(x);
    x -= fp(x, n) / fp_prime(x);
    x -= fp(x, n) / fp_prime(x);
    #undef EPS
    return x;
}

int main() {
    double x, n;
    while (scanf("%lf %lf", &x, &n) != EOF) {
        printf("%lf\n", newton(x, n, f, f_prime));
    }
    return 0;
}
