/*************************************************************************
	> File Name: point.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 15时21分06秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int add(int a, int b) {
    return a + b;
}

typedef int (*func)(int, int);   //func是一种类型

int main() {
    int64_t temp_num;
    int a = 5, *p = &a;
    char b= 'c', *q = &b;
    printf("%d %d\n", a, *p);
    printf("sizeof(*p) = %lu\n", sizeof(*p));
    printf("sizeof(*q) = %lu\n", sizeof(*q));
    p = (int *)&temp_num;
    q = (char *)&temp_num;
    p[1] = 0x3f80;
    p[0] = 0;
    printf("%" PRIx64 "\n", temp_num);
    double *p_ = (double *)&temp_num;
    *p_ = 1.0;
    printf("%" PRIx64 "\n", temp_num);
    //int (*func)(int, int) = add;    //func是变量 
    func func_a = add;
    printf("%d\n", func_a(4, 5));
    return 0;
}
