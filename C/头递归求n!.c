/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月04日 星期三 20时13分01秒
 ************************************************************************/

#include <stdio.h>

void f(int n, int *s) {
    if (n == 1) {
        *s = 1;
        return;
    }
    int temp;
    f(n - 1, &temp);
    *s = temp * n;
}

int main() {
    int n, s;
    scanf("%d", &n);
    f(n, &s);
    printf("%d! = %d\n", n, s);
    return 0;
}
