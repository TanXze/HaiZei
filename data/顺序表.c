/*************************************************************************
	> File Name: 顺序表.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月05日 星期五 16时34分07秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
	int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
	if (index < 0 || index > vector->length) {
        return ERROR;
    }
    for (int i = index + 1; i < vector->length; i++) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
	for (int i = 0; i < vector->length; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
	int m, t, loc, value;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d", &loc, &value);
            printf("%s\n", insert(a, loc, value) == OK ? "success" : "failed");
        } else if (t == 2) {
            scanf("%d", &loc);
            printf("%s\n", delete_node(a, loc) == OK ? "success" : "failed");
        } else if (t == 3) {
            scanf("%d", &value);
            printf("%s\n", search(a, value) == -1 ? "failed" : "success");
        } else {
            print(a);
        }
    }
    return 0;
}
