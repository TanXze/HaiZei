/*************************************************************************
	> File Name: check_size.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月20日 星期六 22时26分15秒
 ************************************************************************/

#include <stdio.h>

int check_size(char *filename, int size, char *dir) {
    struct stat st;
    char buffer[200];
    char cmd[50];
    stat(filename, &st);
    int file_size = st.st_size;
    if (file_size < size) return 0;
    char *cp_file = (char *)malloc(sizeof(char) * 30);
    sprintf(cp_file, "%s%s", dir, filename);
    sprintf(cmd, "cat %s 2>/dev/null", filename);
    FILE *fp = popen(cmd, "r");
    FILE *fd = fopen(cp_file, "w");
    while ((fgets(buffer, 5, fp)) != NULL) {
        fprintf(fd, "%s", buffer);
    }
    pclose(fp);
    fclose(fd);
    return 1;
}
