/*************************************************************************
	> File Name: duotai.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 11时29分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "duotai_head.h"

static int demo_virtual_add(demo *pthis, int value);
static int derived_virtual_add(derived *pthis, int value);

typedef struct vtable {
    int (*padd)(void*, int);
} vtable;

typedef struct class_demo {
    vtable *vptr;
    int i; 
    int j;
} class_demo;

typedef struct class_derived {
    class_demo d;
    int k;
} class_derived;

static vtable g_classdemo_vtr = {
    demo_virtual_add
};

static vtable g_classderived_vtr = {
    derived_virtual_add
};

demo *demo_init(int i, int j) {
    class_demo *d = (class_demo *)malloc(sizeof(class_demo));
    if (d != NULL) {
        d->vptr = &g_classdemo_vtr;
        d->i = i; 
        d->j = j;
    }
    return d;
}

int getI(demo *pthis) {
    class_demo *p = (class_demo *)pthis;
    return p->i;
}

int getJ(demo *pthis) {
    class_demo *p = (class_demo *)pthis;
    return p->j;
}

static int demo_virtual_add(demo *pthis, int value) {
    class_demo *p = (class_demo *)pthis;
    return p->i + p->j + value;
}

int demo_add(demo *pthis, int value) {
    class_demo *p = (class_demo *)pthis;
    return p->vptr->padd(pthis, value);
}

void demo_free(demo *pthis) {
    free(pthis);
    return ;
}

derived *derived_init(int i, int j, int k) {
    class_derived *p = (class_derived *)malloc(sizeof(class_derived));
    if (p != NULL) {
        p->d.vptr = &g_classderived_vtr;
        p->d.i = i;
        p->d.j = j;
        p->k = k;
    }
    return p;
}

int getK(derived *pthis) {
    class_derived *p = (class_derived *)pthis;
    return p->k;
}

static int derived_virtual_add(derived *pthis, int value) {
    class_derived *p = (class_derived *)pthis;
    return p->d.i + p->d.j + p->k + value;
}

int derived_add(derived *pthis, int value) {
    class_derived *p = (class_derived *)pthis;
    return p->d.vptr->padd(pthis, value);
}

void derived_free(derived *pthis) {
    free(pthis);
    return ;
}
