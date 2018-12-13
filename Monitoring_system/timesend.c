#include "head.h"
#include <stdio.h>
#define INS 3

struct mypara {   //每个线程的信息
    const char *s;
    int num;
};

int getfilename (char **bashFileName, int id) {

    int n = 0, stime;
    switch (id) {
        case 0: {
            sprintf(bashFileName[n++], "bash ~/shell/cpu.sh");
            sprintf(bashFileName[n++], "bash ~/shell/mem.sh");
            stime = 5;
        } break;
        case 1: {
            sprintf(bashFileName[n++], "bash ~/shell/disk.sh");
            sprintf(bashFileName[n++], "bash ~/shell/sysinfo.sh");
            sprintf(bashFileName[n++], "bash ~/shell/user.sh");
            stime = 60;
        } break;
        case 2: {
            sprintf(bashFileName[n++], "bash ~/shell/proc.sh");
            stime = 30;
        } break;
        default : {
            printf("para->num error\n");
            return 0;
        }
    }
    return stime;
}

void *func (void *argv) {
    struct mypara *para;
    para = (struct mypara *) argv;
    char **bashFileName = (char **)malloc(sizeof(char *) * (INS + 1));
    for (int i = 0; i < 3; i++) {
        bashFileName[i] = (char *)malloc(sizeof(char) * 30);
    }
    //sprintf(bashFileName[0], "hjkkkkk");
    printf("para->num %d\n", para->num);
    int n = 0, stime;
    stime = getfilename(bashFileName, para->num);
    switch(para->num) {
        case 0: n = 2; break;
        case 1: n = 3; break;
        case 2: n = 1; break;
    }

    FILE *fp;
    #define MAX_N 200
    char *buffer = (char *)malloc(sizeof(char) * 200);
    while (1) {
        printf("para ====== %d  \n", para->num);
        for (int i = 0; i < n; i++) {
            printf("%s\n", bashFileName[i]);
            fp = popen(bashFileName[i], "r");
            pclose(fp);
        }
        sleep(stime);
    }
    return NULL;
}

int main() {
    
    pthread_t t[INS + 1];
    struct mypara para[INS + 1];
    for (int i = 0; i < INS; i++) {
        para[i].s = "Hello world!";
        para[i].num = i;
        if (pthread_create(&t[i], NULL, func, (void *)&para[i]) == -1) {
            printf("error\n");
            exit(1);
        }
    }
    
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    return 0;
}
