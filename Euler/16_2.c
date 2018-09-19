/*************************************************************************
	> File Name: 16_2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月07日 星期二 00时32分43秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int ans[10000] = {0};
    ans[0] = ans[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= ans[0]; i++) {
            ans[i] *= m;
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) ans[0]++;
        }
    }
    int sum = 0;
    for (int i = ans[0]; i >= 1; i--) {
        printf("%d", ans[i]);
        while (ans[i]) {
            sum += ans[i] % 10;
            ans[i] /= 10;
        }
    }
    printf("\n");
    printf("%d\n", sum);
    return 0;
}
