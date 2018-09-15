/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时21分54秒
 ************************************************************************/

#include<stdio.h>

int main(){
    int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int Pmax = 0;
    int str[20][20];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            scanf("%d", &str[i][j]);
        }
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 4; k++){
                int p = 1;
                for(int f = 0; f < 4; f++){
                    int x = i + dir[k][0] * f;
                    int y = j + dir[k][1] * f;
                    if(x < 0 || x >= 20){p = 0;break;}
                    if(y < 0 || y >= 20){p = 0;break;}
                    p *= str[x][y];
                }
                if(p > Pmax){
                    Pmax = p;
                }
            }
        }
    }
    printf("%d\n", Pmax);
    return 0;
}
