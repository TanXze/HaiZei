/*************************************************************************
	> File Name: testcase2.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 19时40分14秒
 ************************************************************************/

#ifndef _TESTCASE2_H
#define _TESTCASE2_H
#include "test.h"
#include "cut.h"

TEST(test, cut_func) {
    EXPECT_EQ(cut(4), 5);
    EXPECT_NE(cut(5), 6);
    EXPECT_GT(cut(6), 7);
    EXPECT_LT(cut(7), 8);
    EXPECT_GE(cut(8), 9);
    EXPECT_LE(cut(9), 1);
}

#endif
