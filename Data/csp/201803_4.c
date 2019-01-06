/*************************************************************************
	> File Name: 201803_4.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月28日 星期日 15时34分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, str[3][3];
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                scanf("%d", &str[j][k]);
            }
        }
    }
}
