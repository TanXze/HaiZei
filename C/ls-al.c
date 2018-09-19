/*************************************************************************
	> File Name: ls-al.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月17日 星期一 15时25分01秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(){
    DIR *dir;
    dir = opendir(".");
    char *n_name;
    struct dirent *d_dir;
    struct stat st;
    memset(&st, 0, sizeof(st));
    while(d_dir = readdir(dir)){
        n_name = d_dir->d_name;
        stat(n_name, &st);
        int n_size, n_link;
        n_link = st.st_nlink;
        n_size = st.st_size;

        char n_dir;
        if(S_ISREG(st.st_mode)){
            n_dir = '-';
        }else if(S_ISDIR(st.st_mode)){
            n_dir = 'd';
        }else if(S_ISCHR(st.st_mode)){
            n_dir = 'c';
        }else if(S_ISBLK(st.st_mode)){
            n_dir = 'b';
        }else if(S_ISFIFO(st.st_mode)){
            n_dir = 'p';
        }else if(S_ISLNK(st.st_mode)){
            n_dir = 'l';
        }else if(S_ISSOCK(st.st_mode)){
            n_dir = 's';
        }

        char n_power[10] = {};
        if(S_IRUSR & st.st_mode){
            n_power[0] = 'r';
        }else{
            n_power[0] = '-';
        }
        if(S_IWUSR & st.st_mode){
            n_power[1] = 'w';
        }else{
            n_power[1] = '-';
        }
        if(S_IXUSR & st.st_mode){
            n_power[2] = 'x';
        }else{
            n_power[2] = '-';
        }
        if(S_IRGRP & st.st_mode){
            n_power[3] = 'r';
        }else{
            n_power[3] = '-';
        }
        if(S_IWGRP & st.st_mode){
            n_power[4] = 'w';
        }else{
            n_power[4] = '-';
        }
        if(S_IXGRP & st.st_mode){
            n_power[5] = 'x';
        }else{
            n_power[5] = '-';
        }
        if(S_IROTH & st.st_mode){
            n_power[6] = 'r';
        }else{
            n_power[6] = '-';
        }
        if(S_IWOTH & st.st_mode){
            n_power[7] = 'w';
        }else{
            n_power[7] = '-';
        }
        if(S_IXOTH & st.st_mode){
            n_power[8] = 'x';
        }else{
            n_power[8] = '-';
        }

        struct passwd *u_uid;
        u_uid = getpwuid(st.st_uid);
        char *n_uid = u_uid->pw_name;

        struct group *gr_gid;
        gr_gid = getgrgid(st.st_gid);
        char *n_gid = gr_gid->gr_name;

        struct tm *local_time;
        local_time = localtime(&st.st_ctime);
        int n_num = local_time->tm_mon;
        char *n_mon;
        int n_day = local_time->tm_mday;
        int n_hour = local_time->tm_hour;
        int n_min = local_time->tm_min;
        switch(n_num){
            case 0:n_mon = "1月";break;
            case 1:n_mon = "2月";break;
            case 2:n_mon = "3月";break;
            case 3:n_mon = "4月";break;
            case 4:n_mon = "5月";break;
            case 5:n_mon = "6月";break;
            case 6:n_mon = "7月";break;
            case 7:n_mon = "8月";break;
            case 8:n_mon = "9月";break;
            case 9:n_mon = "10月";break;
            case 10:n_mon = "11月";break;
            case 11:n_mon = "12月";break;
            default:break;
        }

        if(n_dir == 'd'){
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  \33[34m\33[1m%s\33[0m/\n", n_dir, n_power, n_link, n_uid, n_gid, n_size, n_mon, n_day, n_hour, n_min, n_name);
        }else if(n_dir == '-' && (n_power[2] == 'x' || n_power[5] == 'x' || n_power[8] == 'x')){
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  \33[32m\33[1m%s\33[0m*\n", n_dir, n_power, n_link, n_uid, n_gid, n_size, n_mon, n_day, n_hour, n_min, n_name);
        }else{
            printf("%c%s %-3d %-10s %-10s %-7d %-3s %-4d %2d:%-2d  %s\n", n_dir, n_power, n_link, n_uid, n_gid, n_size, n_mon, n_day, n_hour, n_min, n_name);
        }
    }
    return 0;
}
