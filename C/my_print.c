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

void printNum(int temp);
void my_printD(int temp);

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch (frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int); //, x = 0;
                        /*while (temp) {
                            x = x * 10 + temp % 10;
                            temp /= 10;
                        }
                        while (x) {
                            putchar(x % 10 + '0');
                            x /= 10;
                        }*/
                        my_printD(temp);
                    } break;
                    default : 
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default : 
                putchar(frm[i]);
        }
    }
    return cnt;
}

void printNum (int temp) {
    if (temp == 0) return;
    printNum(temp / 10);
    putchar(temp % 10 + '0');
}

void my_printD (int temp) {
    if (temp < 0) {
        putchar('-');
        temp = -temp;
    }
    if (temp == 0) {
        putchar('0');
    } else {
        printNum(temp);
    }
}

int main(){
    my_printf("Hello World\n");
    my_printf("n = %d\n", 123);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
