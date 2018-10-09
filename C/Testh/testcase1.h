/*************************************************************************
	> File Name: testcase1.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时49分21秒
 ************************************************************************/

#ifndef _TESTCASE1_H
#define _TESTCASE1_H
#include "test.h"
#include "newton.h"

TEST(test, newton_func) {
    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(newton(i), 4);
        EXPECT_NE(newton(i), 1);
        EXPECT_GT(newton(i), 6);
        EXPECT_LT(newton(i), 2);
        EXPECT_GE(newton(i), 8);
        EXPECT_LE(newton(i), 6);
    }
}

#endif
