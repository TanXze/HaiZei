/*************************************************************************
	> File Name: test.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月04日 星期四 17时52分57秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#include <stdio.h>

#define PASS "\033[32mPASS\033[0m"
#define FAIL "\033[31mFAIL\033[0m"

typedef int (*Prime)(int x);
typedef bool EXPECT(Prime is_prime, int a);

void TEST(char *test, char *func_name) {
    printf("[%s, %s_func]\n", test, func_name);
    int total = 0, expect_cnt = 0;
    while (EXPECT(, a)) {
        printf(" == %d %s\n", , a, EXPECT(, a));
        total++;
        if (EXPECT(, a) == 1) {
            expect_cnt++;
        }
    }
    if (total == expect_cnt) {
        printf("[ %s ] total : %d, expect_cnt : %d\n", PASS, total, expect_cnt);
    } else {
        printf("[ %s ] total : %d, expect_cnt : %d\n", FAIL, total, expect_cnt);
    }
}

void RUN_ALL_TEST() {

}

#endif
