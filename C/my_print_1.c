/*************************************************************************
	> File Name: my_print_1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月09日 星期二 17时19分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

void print_num(int temp) {
    if (temp == 0) return ;
    print_num(temp / 10);
    putchar(temp % 10 + '0');
}

int my_print(const char *frm, ...) {
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
                            putchar('-');
                            p1 = -p1;
                            p2 = -p2;
                        }
                        print_num(p1);
                        putchar(p2 + '0');
                        cnt++;
                    } break;
                    default : 
                    printf("error\n");
                    return -1;
                }
            } break;
            default : 
            putchar(frm[i]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    my_print("hello world\n");
    my_print("%d\n", 0);
    my_print("%d\n", 12000);
    my_print("%d\n", -345);
    my_print("%d\n", INT32_MIN);
    my_print("%d\n", INT32_MAX);
    return 0;
}
