/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时53分13秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int a = 1, b = 2, c;
    int num = 0;
    while (b < 4000000) {
        if (b % 2 == 0) {
            num += b;
        }
        c = b;
        b = a + b;
        a = c;
    }
    printf("%d\n", num);
    return 0;
}
