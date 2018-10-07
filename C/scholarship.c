/*************************************************************************
	> File Name: scholarship.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月06日 星期六 18时41分42秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int C, Math, English;
    scanf("%d %d %d", &C, &Math, &English);
    int score = 75;
    if (C >= 90) {
        score += 10;
    }
    if (Math >= 90) {
        score += 8;
    }
    if (English >= 90) {
        score += 7;
    }
    printf("%d\n", score);
    return 0;
}
