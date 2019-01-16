/*************************************************************************
	> File Name: inherit_main.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时34分47秒
 ************************************************************************/

#include <stdio.h>
#include "inherit_head.h"

int main() {
    demo *p = demo_init(1, 2);
    printf("i = %d\n", getI(p));
    printf("j = %d\n", getJ(p));
    printf("i + j = %d\n", add(p, 3));
    free_demo(p);
    deverid *d = deverid_init(1, 2, 3);
    printf("i = %d\n", getI(d));
    printf("j = %d\n", getJ(d));
    printf("k = %d\n", getK(d));
    printf("add = %d\n", add1(d, 5));
    free_deverid(d);
    return 0;
}
