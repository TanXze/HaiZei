/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月01日 星期日 20时14分42秒
 ************************************************************************/

#include <stdio.h>

int main() {
    freopen("/dev/null", "w", stderr);
    char str[1000];
    while (scanf("%[^\n]s", str)!=EOF) {
        getchar();
        printf("%d", fprintf(stderr, "%s", str));
    }
    return 0;
}
