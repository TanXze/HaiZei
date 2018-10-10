/*************************************************************************
	> File Name: my_print.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月20日 星期四 20时27分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int print_int(int x, int flag){
    if (x == 0) {
        flag && putchar('0');
        return !!(flag);
    }
    int temp = x, ret = 0;
    x = 0;
    if (temp < 0) {
        temp = -temp, printf("-");
    }
    while (temp) {
        x = x * 10 + temp % 10;
        temp /= 10;
    }
    while (x) {
        putchar(x % 10 + '0');
        x /= 10;
        ret++;
    }
    return ret;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch (frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int);
                        int p1 = temp / 10, p2 = temp % 10;
                        if (temp < 0) {
                            p1 = -p1, p2 = -p2;
                            putchar('-'); cnt++;
                        }
                        cnt += print_int(p1, 0);
                        cnt += print_int(p2, 1);
                    } break;
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default : 
            putchar(frm[i]);
                cnt++; 
        }
    }
    return cnt;
}

int main(){
    my_printf("Hello World\n");
    my_printf("n = %d\n", 123);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", 0);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
