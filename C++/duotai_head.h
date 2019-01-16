/*************************************************************************
	> File Name: duotai.h
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 11时26分57秒
 ************************************************************************/

#ifndef _DUOTAI_H
#define _DUOTAI_H
typedef void demo;
typedef void derived;

demo *demo_init(int i, int j);
int getI(demo *pthis);
int getJ(demo *pthis);
int demo_add(demo *pthis, int value);
void demo_free(demo *pthis);

derived *derived_init(int i, int j, int k);
int getK(derived *pthis);
int derived_add(derived *pthis, int value);
void derived_free(derived *pthis);
#endif
