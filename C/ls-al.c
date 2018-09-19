/*************************************************************************
	> File Name: ls-al.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月17日 星期一 15时25分01秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
    DIR *dir;
    dir = opendir(".");
    char *name;
    struct dirent *d_dir;
    struct stat st;
    while (d_dir = readdir(dir)) {
        name = d_dir -> d_name;
        stat(name, &st);
        int size, link;
        link = st.st_nlink;
        size = st.st_size;

        char type;
        if (S_ISREG(st.st_mode)) {
            type = '-';
        } else if (S_ISDIR(st.st_mode)) {
            type = 'd';
        } else if (S_ISCHR(st.st_mode)) {
            type = 'c';
        } else if (S_ISBLK(st.st_mode)) {
            type = 'b';
        } else if (S_ISFIFO(st.st_mode)) {
            type = 'p';
        } else if (S_ISLNK(st.st_mode)) {
            type = 'l';
        } else if (S_ISSOCK(st.st_mode)) {
            type = 's';
        }

        char limit[10] = {};
        if (S_IRUSR & st.st_mode) {
            limit[0] = 'r';
        } else {
            limit[0] = '-';
        }
        if (S_IWUSR & st.st_mode) {
            limit[1] = 'w';
        } else {
            limit[1] = '-';
        }
        if (S_IXUSR & st.st_mode) {
            limit[2] = 'x';
        } else {
            limit[2] = '-';
        }
        if (S_IRGRP & st.st_mode) {
            limit[3] = 'r';
        } else {
            limit[3] = '-';
        }
        if (S_IWGRP & st.st_mode) {
            limit[4] = 'w';
        } else {
            limit[4] = '-';
        }
        if (S_IXGRP & st.st_mode) {
            limit[5] = 'x';
        } else {
            limit[5] = '-';
        }
        if (S_IROTH & st.st_mode) {
            limit[6] = 'r';
        } else {
            limit[6] = '-';
        }
        if (S_IWOTH & st.st_mode) {
            limit[7] = 'w';
        } else {
            limit[7] = '-';
        }
        if (S_IXOTH & st.st_mode) {
            limit[8] = 'x';
        } else {
            limit[8] = '-';
        }

        struct passwd *uid;
        uid = getpwuid(st.st_uid);
        char *user = uid -> pw_name;

        struct group *gid;
        gid = getgrgid(st.st_gid);
        char *group = gid -> gr_name;

        struct tm *local_time;
        local_time = localtime(&st.st_ctime);
        int num = local_time -> tm_mon;
        char *mon;
        int day = local_time -> tm_mday;
        int hour = local_time -> tm_hour;
        int min = local_time -> tm_min;
        switch (num) {
            case 0: mon = "1月"; break;
            case 1: mon = "2月"; break;
            case 2: mon = "3月"; break;
            case 3: mon = "4月"; break;
            case 4: mon = "5月"; break;
            case 5: mon = "6月"; break;
            case 6: mon = "7月"; break;
            case 7: mon = "8月"; break;
            case 8: mon = "9月"; break;
            case 9: mon = "10月"; break;
            case 10: mon = "11月"; break;
            case 11: mon = "12月"; break;
            default: break;
        }

        if (type == 'd') {
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  \33[34m\33[1m%s\33[0m/\n", type, limit, link, user, group, size, mon, day, hour, min, name);
        } else if (type == '-' && (limit[2] == 'x' || limit[5] == 'x' || limit[8] == 'x')) {
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  \33[32m\33[1m%s\33[0m*\n", type, limit, link, user, group, size, mon, day, hour, min, name);
        } else {
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  %s\n", type, limit, link, user, group, size, mon, day, hour, min, name);
        }
    }
    return 0;
}
