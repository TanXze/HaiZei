/*************************************************************************
	> File Name: ls.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月16日 星期三 11时51分08秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<algorithm>

using namespace std;

bool cmp(string a, string b){
    return a < b;
}

int ls(char *DirName){
    DIR *dir;
    char str[100];
    string res[100];
    struct dirent *rent;
    cout << DirName << ":" << endl;
    dir = opendir(DirName);
    int cnt = 0;
    while((rent = readdir(dir))){
        strcpy(str, rent -> d_name);
        if(str[0] == '.') continue;
        if(!str) continue;
        res[cnt++] = str;
    }
    sort(res, res + cnt, cmp);
    for(int i = 0; i < cnt; i++){
        cout << res[i] << "\t";
    }
    cout << endl << endl;
    closedir(dir);
    return 0;
}

int main(int argc, char *argv[]){
    if(argc == 1){
        ls(".");
    }else if(argc == 2){
        ls(argv[1]);
    }else{
        for(int i = 1; i < argc; i++){
            ls(argv[i]);
        }
    }
    return 0;
}
