/*************************************************************************
	> File Name: 素数筛.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月23日 星期一 16时57分34秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define MAX 100000

int32_t prime[MAX + 5] = {0};

int32_t main() {
    for (int32_t i = 2; i * i <= MAX; i++) {
        if (!prime[i]) {
            for (int32_t j = 2 * i; j <= MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%s\n", prime[n] == 0 ? "yes" : "NO");
    }
    return 0;
}
