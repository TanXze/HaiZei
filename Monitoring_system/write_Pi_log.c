/*************************************************************************
	> File Name: write_Pi_log.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月30日 星期日 15时46分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int write_Pi_log(char *PiHealthLog, const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    FILE *fp;
    fp = fopen(PiHealthLog, "w");
    for (int i = 0; format[i]; i++) {
        switch (format[i]) {
            case '%' : {
                i++;
                switch (format[i]) {
                    case 'd' : {
                        fprintf(fp, format, va_arg(arg, int));
                    } break;
                    case 's' : {
                        fprintf(fp, format, va_arg(arg, char *));
                    } break;
                    case 'c' : {
                        fprintf(fp, format, va_arg(arg, char));
                    } break;
                    default : {
                        fprintf(stderr, "error : unknow %%%c\n", format[i]);
                        exit(1);
                    }
                }
            } break;
            default : {
                putchar(format[i]);
            }
        }
    }
}

int main() {
    char str[10] = "hello";
    write_Pi_log("Pi.log", "write %s into ./logfile/write.log\n", str);
    return 0;
}
