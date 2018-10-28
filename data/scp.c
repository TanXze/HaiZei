/*************************************************************************
	> File Name: scp.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月28日 星期日 09时41分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    char **data, *name;
    int size, length;
} Vector;

Vector *init(int size) {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (char **)malloc(sizeof(char *) * size);
    v->size = size;
    v->length = 0;
    return v;
}

void insert(Vector *v, const char *str) {
    if (v->length == v->size) return ;
    v->data[v->length++] = strdup(str);
    return ;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

Vector *getVector(char *str) {
    int n = 0;
    for (int i = 0; str[i]; i++) {
        n += str[i] == '/';
    }
    Vector *v = init(2 * n + 1);
    insert(v, "/");
    str++;
    char *now = str;
    while (now[0]) {
        while (str[0] && str[0] != '/') str++;
        if (str[0] == '/') {
            str[0] = 0;
            insert(v, now);
            insert(v, "/");
            str++;
        } else {
            insert(v, now);
        }
        now = str;
    }
    return v;
}

void output(Vector *v) {
    if (strcmp(v->data[1], "articles") == 0) {
        for (int i = 3; i < v->length; i += 2) {
            printf(" %s", v->data[i]);
        }
        printf("\n");
    } else if (strcmp(v->data[1], "static") == 0){
        printf(" ");
        for (int i = 3; i < v->length; i++) {
            printf("%s", v->data);
        }
    }
    return ;
}

int gettype(const char *str) {
    if (strcmp(str, "<int>") == 0) return 1;
    if (strcmp(str, "<str>") == 0) return 2;
    if (strcmp(str, "<path>") == 0) return 3;
    return 0;
}

int match_node(const char *p, const char *t) {
    int type = gettype(p), flag = 1;
    switch (type) {
        case 0: return (strcmp(p, t) == 0 ? type : -1);
        case 1: {
            for (int i = 0; t[i]; i++) {
                if (t[i] < '0' || t[i] > '9') return -1;
            }
            return type;
        } break;
        case 2: 
        case 3: return type;
    }
    return -1;
}

int match(Vector *v1, Vector *v2) {
    if (v2->length < v1->length) return 0;
    for (int i = 0; i < v1->length; i++) {
        int type;
        if ((type = match_node(v1->data[i], v2->data[i])) == -1) return 0;
        if (type == 3) return 1;
    }
    return v1->length == v2->length;
}

Vector *rules[105];

int main() {
    char str[1000];
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        rules[i] = getVector(str);
        scanf("%s", str);
        rules[i]->name = strdup(str);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        Vector *now = getVector(str);
        int j = 0;
        while (j < m && match(rules[j], now) == 0) ++j;
        if (j == m) {
            printf("404\n");
        } else {
            printf("%s", rules[j]->name);
            output(now);
        }
    }
    return 0;
}
