/*************************************************************************
	> File Name: check_size.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月20日 星期六 22时26分15秒
 ************************************************************************/

#include "head.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int check_size(char *filename, int size, char *dir) {
    struct stat st;
    char name[100] = {0}, cmd[100] = {0}, basename[10] = {0};
    time_t _time;
    struct tm *lt;
    stat(filename, &st);
    int size_real = st.st_size / 1048576;
    if (size_real > size) return 0;
    sprintf(name, "basename %s", filename);
    FILE *stream = popen(name, "r");
    fgets(basename, sizeof(basename), stream);
    time(&_time);
    lt = localtime(&_time);
    sprintf(cmd, "tar -czvf %s/%s.tar.gz %s", dir, basename, filename);
    system(cmd);
    return 0;
}

int main() {
    check_size("socket_lient.c", 1, "~/HaiZei/");
    return 0;
}
