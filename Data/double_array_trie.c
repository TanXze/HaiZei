/*************************************************************************
	> File Name: double_array_trie.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月06日 星期日 15时15分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int flag;
    struct Node *next[26];
} Node;

typedef struct DATNode {
    int base, check;
} DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
            cnt += 1;
        }
        p = p-> next[str[i] - 'a'];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0;
    while (!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

int Transform(Node *node, DATNode *trie, int ind) {
    if (ind == 1) trie[ind].check = 1; 
    if (node->flag) trie[ind].check = -trie[ind].check;
    trie[ind].base = getBase(node, trie);
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    int ret = ind;
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        int temp = Transform(node->next[i], trie, trie[ind].base + i);
        if (temp > ret) ret = temp;
    }
    return ret;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base + delta;
    }
    return trie[p].check < 0;
}

int main() {
    int n, cnt1 = 1, cnt2 = 0;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt1 += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt1 * 10);
    cnt2 += Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }
    printf("Normal Trie : %ld\n", cnt1 * sizeof(Node));
    printf("Double Array Trie : %ld\n", cnt2 * sizeof(DATNode));
    for (int i = 0; i <= cnt2; i++) {
        printf("%d %d %d\n", i, trie[i].base, trie[i].check);
    }
    return 0;
}
