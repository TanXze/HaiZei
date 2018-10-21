/*************************************************************************
	> File Name: raddix_sort.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月21日 星期日 11时09分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void raddix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65537] = {0};
    for (int i = 0; i < n; i++) cnt[(num[i] & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[((temp[i] >> 16) & 0xffff) + 1]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
    return ;
}

void output(int *num, int n) {
    for (int i = 0; i < n; i++) {
        i && num[i] < num[i - 1] && printf("error");
        printf("%d ", num[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int num[20];
    for (int i = 0; i < 20; i++) {
        num[i] = rand() % 100;
    }
    raddix_sort(num, 20);
    output(num, 20);
    return 0;
}
