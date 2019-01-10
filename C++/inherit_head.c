/*************************************************************************
	> File Name: inherit_head.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时27分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "inherit_head.h"

typedef struct class_demo {
    int i;
    int j;
} class_demo;

typedef struct Derived {
    class_demo d;
    int k;
} Derived;

demo* demo_init(int i, int j) {
    class_demo *p = (class_demo *)malloc(sizeof(class_demo));
    if (p != NULL) {
        p->i = i;
        p->j = j;
    }
    return p;
}

int getI(demo *pthis) {
    class_demo *p = (class_demo *)pthis;
    return p->i;
}

int getJ(demo *pthis) {
    class_demo *p = (class_demo *)pthis;
    return p->j;
}

int add(demo *pthis, int value) {
    class_demo *p = (class_demo *)pthis;
    return p->i + p->j + value;
}

void free_demo(demo *pthis) {
    free(pthis);
}
