/*************************************************************************
	> File Name: ol11.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月22日 星期日 15时45分04秒
 ************************************************************************/

#include <stdio.h>
int main(){
    int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int Pmax = 0;
    int str[20][20];
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            scanf("%d", &str[i][j]);
            printf("%2d ", str[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 4; k++){
                int P = 1;
                for(int f = 0; f < 4; f++){
                    int x = i + dir[k][0] * f;
                    int y = j + dir[k][1] * f;
                    if(x < 0 || x >= 20) {P = 0; break;}
                    if(y < 0 || y >= 20) {P = 0; break;}
                    P *= str[x][y];
                }
                if(P > Pmax){
                    Pmax = P;
                }
            }
        }
    }
    printf("%d", Pmax);
    return 0;
}
