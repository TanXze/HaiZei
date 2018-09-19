/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时01分48秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

#define NUM 600851475143

int main() {
    int64_t num = NUM;
    int64_t max_prime;
    for (int64_t i = 2; i * i <= NUM; i++) {
        while (num % i == 0) {
            num /= i;
            max_prime = i;
        }
    }
    if (num != 1) max_prime = num;
    printf("%"PRId64"\n", max_prime);
    return 0;
}
