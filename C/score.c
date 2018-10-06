/*************************************************************************
	> File Name: score.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月06日 星期六 17时17分33秒
 ************************************************************************/

#include <stdio.h>

int main() {
    char gender, duty;
    scanf("%c,%c", &gender, &duty);
    int score = 3;
    if (gender == 'f') {
        score += 2;
    }
    if (duty == 'y') {
        score++;
    }
    printf("%d\n", score);
    return 0;
} 
