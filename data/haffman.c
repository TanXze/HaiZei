/*************************************************************************
	> File Name: haffman.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月28日 星期日 20时01分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return ;
}

Node *build_haffman(Node **arr, int n) {
    Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    for (int i = 0; i < n - 1; i++) {
        int ind1 = arr[0]->freq > arr[1]->freq;
        int ind2 = arr[0]->freq <= arr[1]->freq;
        printf("init : %d %d\n", ind1, ind2);
        for (int j = 2; j < n - i; j++) {
            if (arr[j]->freq <= arr[ind1]->freq) {
                ind2 = ind1;
                ind1 = j;
            } else if (arr[j]->freq < arr[ind2]->freq) {
                ind2 = j;
            }
        }
        printf("first: %c %d  second: %c %d\n", arr[ind1]->key, arr[ind1]->freq, arr[ind2]->key, arr[ind2]->freq);
        Node *temp = getNewNode(0, arr[ind1]->freq + arr[ind2]->freq);
        temp->lchild = arr[ind1];
        temp->rchild = arr[ind2];
        swap_node(arr + n - i - 1, arr + ind1);
        swap_node(arr + n - i - 2, arr + ind2);
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    char code[256][20] = {0}, buff[20];
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%c %d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", (char)i, code[i]);
    }
    clear(root);
    return 0;
}
