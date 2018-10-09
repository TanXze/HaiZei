/*************************************************************************
	> File Name: testcase3.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时26分55秒
 ************************************************************************/

#ifndef _TESTCASE3_H
#define _TESTCASE3_H
#include "test.h"
#include "gcd.h"

TEST(test, gcd_func) {
    EXPECT_EQ(gcd(3, 5), 1);
    EXPECT_NE(gcd(5, 8), 4);
    EXPECT_GT(gcd(2, 4), 1);
    EXPECT_LT(gcd(3, 9), 6);
    EXPECT_GE(gcd(5, 8), 7);
    EXPECT_LE(gcd(8, 12), 4);
}

#endif
