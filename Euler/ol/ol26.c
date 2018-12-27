/*************************************************************************
	> File Name: ol26.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月06日 星期日 09时18分59秒
 ************************************************************************/

#include<stdio.h>

int get_circle_length(int d){
    int first_ind[1000] = {0};
    int y = 1, ind = 1;
    do{
        first_ind[y] = (ind++);
        y = (y * 10) % d;
    } while (y && first_ind[y] == 0);
    if(y == 0)return 0;
    return ind - first_ind[y];
}

int main(){
    int max_length = 0, ans_num;
    for(int i = 2; i < 1000; i++){
        if(get_circle_length(i) > max_length){
            ans_num = i;
            max_length = get_circle_length(i);
        }
    }
    printf("%d\n", ans_num);
    return 0;
}
