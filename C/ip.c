/*************************************************************************
	> File Name: ip.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月10日 星期日 13时07分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

union Ip {
    int num;
    char part[4];
};

int main() {
    int num[4];
    scanf("%d.%d.%d.%d", num + 3, num + 2, num + 1, num + 0);
    union Ip ip;
    for (int i = 3; i >= 0; --i) {
        ip.part[i] = num[i] & ((1 << 8) - 1);
        printf("%02X\n", num[i]);
    }
    printf("%08X\n", ip.num);
    return 0;
}
