/*************************************************************************
	> File Name: huiwen.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月13日 星期日 15时19分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int is_valid(char *str, int i, int j) {
    while (i < j) {
        if (str[i++] != str[j--]) return 0;
    }
    return 1;
}

void expand(char *str, int i, int j, int n) {
    while (i >= 0 && j < n && str[i] == str[j]) {
        char c = str[j + 1];
        str[j + 1] = 0;
        printf("%s\n", str + i);
        str[j + 1] = c;
        i--;
        j++;
    }
    return ;
}

int main() {
    char str[1000];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; str[i]; i++) {
        /*for(int j = i; str[j]; j++) {
            if (is_valid(str, i, j)) {
                char c = str[j + 1];
                str[j + 1] = 0;
                printf("%d %d(%s)\n", i, j, str + i);
                str[j + 1] = c;
            }
        }*/
        expand(str, i, i, len);
        expand(str, i, i + 1, len);
    }
}
