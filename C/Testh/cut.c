/*************************************************************************
	> File Name: newton.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时32分45秒
 ************************************************************************/

#include <stdio.h>

int cude(int n) {
    return n * n * n;
}

int cut(int x) {
    int range = x;
    if (x < 0) range = -x;
    int max = range, min = -range;
    int mid = (max + min) >> 1;
    while (min <= max) {
        if (cude(mid) == x) break;
        if (cude(mid) < x) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
        mid = (max + min) >> 1;
    }
    return cude(mid) == x;
}
