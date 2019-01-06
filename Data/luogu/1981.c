/*************************************************************************
	> File Name: 1981.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月23日 星期二 13时43分00秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_N 1300000
#define MOD_NUM 10000
#define INF 0x3f3f3f3f

char str[MAX_N] = {0};

int calc(char *str) {
    int len = strlen(str);
    for (int i = 0; str[i]; i++) str[i] = (str[i] == '+' ? 0 : str[i]);
    int total = 0;
    for (int j = 0; j < len; j += strlen(str + j) + 1) {
        int num = 0, p = 1;
        for (int i = j; str[i]; i++) {
            switch (str[i]) {
                case '*' : p *= num; p %= MOD_NUM; num = 0; break;
                default : num = num * 10 + str[i] - '0';
            }
        }
        p *= num;
        p %= MOD_NUM;
        total += p;
        total %= MOD_NUM;
    }
    return total;
}

int main() {
    scanf("%s", str);
    printf("%d\n", calc(str));
    return 0;
}
