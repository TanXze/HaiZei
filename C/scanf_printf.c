/*************************************************************************
	> File Name: scanf_printf.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月06日 星期六 17时27分04秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int total, fail, n, pass;
    float pass_rate;
    scanf("%d %d %d", &total, &fail, &n);
    pass = total - fail;
    pass_rate = (pass * 1.0) / (total * 1.0) * 100;
    printf("%*d\n%*d\n%5.2f%%\n", n, pass, n, total, pass_rate);
    return 0;
}
