/*************************************************************************
	> File Name: AC_deep.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月20日 星期日 09时44分01秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 26
#define BEGIN_IETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE], *fail, *father;
} Node;

Node *getNewNode(Node *father) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->father = father;
    return p;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BEGIN_IETTER] == NULL) {
            p->next[str[i] - BEGIN_IETTER] = getNewNode(p);
        }
        p = p->next[str[i] - BEGIN_IETTER];
    }
    p->flag = 1;
    return ;
}

//递归建立AC
void build_ac(Node *node) {
    if (node == NULL) return ; //递归ｐ为根结点，p->father(root)为空
    if (node->fail == NULL) build_ac(node->father);
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        if (node->next[i]->fail) continue;
        Node *p = node->fail, *pre_p = node;  //当前结点失败指针
        while (p && p->next[i] == NULL) {
            if (p->fail == NULL) build_ac(p->father);
            pre_p = p;
            p = p->fail;
        }
        if (p == NULL) p = pre_p;
        else p = p->next[i];
        node->next[i]->fail = p;
        build_ac(node->next[i]);
    }
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) clear(node->next[i]);
    free(node);
    return ;
}

int main() {
    Node *root = getNewNode(NULL);
    return 0;
}
