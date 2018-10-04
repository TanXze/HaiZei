/*************************************************************************
	> File Name: union.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 09时59分52秒
 ************************************************************************/

#include <iostream>

union IP {
    struct {
        unsigned char arr[4];
    } ip;
    unsigned int num;
};

int main() {
    int a, b, c ,d;
    IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
