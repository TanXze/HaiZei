/*************************************************************************
	> File Name: 36.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 13时28分49秒
 ************************************************************************/

#include <stdio.h>

int check(int a, int base) {
    int x = 0;
    while (a) {
        x = x * base + a % base;
        a /= base;
    }
    return x;
}

int main() {
    int sum = 0, base2, base10;
    for (int i = 1; i < 1000000; i++) {
        base2 = check(i, 2);
        base10 = check(i, 10);
        if (base2 == base10 && base10 == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
