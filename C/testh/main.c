/*************************************************************************
	> File Name: main.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月07日 星期日 11时33分13秒
 ************************************************************************/

#include <stdio.h>
#include "test.h"

#ifndef TEST_CASE
    #include "testcase1.h"
    #include "testcase2.h"
#endif

int main() {
    return RUN_ALL_TEST();
}
