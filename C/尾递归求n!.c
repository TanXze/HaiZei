/*************************************************************************
	> File Name: 9.cmZ
	> Mail: 
	> Created Time: 2018年04月04日 星期三 19时29分21秒
 ************************************************************************/

#include <stdio.h>

int f(int n) {
    if(n == 1) {
        return 1;
    }
    return f(n - 1) * n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d != %d", n, f(n));
    return 0;
}

