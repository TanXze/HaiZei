/*************************************************************************
	> File Name: Double_Array_Trie.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月06日 星期日 15时57分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DATNode {
    int base, check;
} DATNode;

DATNode trie[500];

void search(int x, int k, char *str) {
    if (trie[x].check < 0) {
        printf("%s\n", str);
    }
    for (int i = 0; i < 26; i++) {
        int check = abs(trie[trie[x].base + i].check);
        if (check == x && trie[x].base + i != check) {
            str[k] = i + 'a';
            str[k + 1] = 0;
            search(trie[x].base + i, k + 1, str);
        }
    }
    return ;
}

int main() {
    int x, base, check;
    char str[15] = {0};
    while (scanf("%d %d %d", &x, &base, &check) != EOF) {
        trie[x].base = base;
        trie[x].check = check;
    }
    search(1, 0, str);
    return 0;
}
