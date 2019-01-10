/*************************************************************************
	> File Name: inherit_head.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时25分32秒
 ************************************************************************/

#ifndef _INHERIT_HEAD_H
#define _INHERIT_HEAD_H
typedef void demo;
demo* demo_init(int i, int j);
int getI(demo *pthis);
int getJ(demo *pthis);
int add(demo *pthis, int value);
void free_demo(demo *pthis);
#endif
