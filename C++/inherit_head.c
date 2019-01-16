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

typedef struct class_deverid {
    class_demo d;
    int k;
} class_deverid;

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

deverid *deverid_init(int i, int j, int k) {
    class_deverid *p = (class_deverid *)malloc(sizeof(class_deverid));
    if (p != NULL) {
        p->d.i = i;
        p->d.j = j;
        p->k = k;
    }
    return p;
}

int getK(deverid *pthis) {
    class_deverid *p = (class_deverid *)pthis;
    return p->k;
}

int add1(deverid *pthis, int value) {
    class_deverid *p = (class_deverid *)pthis;
    return p->d.i + p->d.j + p->k + value;
}

void free_deverid(deverid *pthis) {
    free(pthis);
}
