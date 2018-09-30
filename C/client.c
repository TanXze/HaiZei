/*************************************************************************
	> File Name: client.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月29日 星期六 14时27分21秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <linux/ioctl.h>
#include<fcntl.h>
#include<sys/stat.h>
#define MAXBUF 512

#define DEV_IOC_MAGIC '0xee' //定义幻数


#define DEV_IOCPRINT  _IO(DEV_IOC_MAGIC, 1)
#define DEV_IO_HIGH   _IO(DEV_IOC_MAGIC, 2)
#define DEV_IO_LOW    _IO(DEV_IOC_MAGIC, 3)

#define DEV_IOC_MAXNR 3

char send_buf[MAXBUF+1];
int fd;
void *thread(void *x)  
{   
    int cmd;
    char buf[BUFSIZ];
    int new_fd = *((int*)x);
    while(recv(new_fd,buf,BUFSIZ,0)>0)
    {
        //int len=recv(new_fd,buf,BUFSIZ,0);
        if(strcmp(buf,"1")==0)
        {
            printf("<--- Call DEV_IO_HIGH --->\n");
            cmd = DEV_IO_HIGH;
            if (ioctl(fd, cmd) < 0)
            {
                printf("Call cmd DEV_IO_HIGH fail\n");
            }
            printf("NOW,GPIO is High.\n");
        }
        if(strcmp(buf,"0")==0)
        {
            printf("<--- Call DEV_IO_LOW --->\n");
            cmd = DEV_IO_LOW;
            if (ioctl(fd, cmd) < 0)
            {
                printf("Call cmd DEV_IO_LOW fail\n");
            }
            printf("NOW,GPIO is Low.\n");
        }
        printf("client:received:%s\n",buf);
    }
    /*while(1)
    {
        bzero(send_buf, MAXBUF + 1);
        scanf("%s",send_buf);
        send(new_fd, send_buf, strlen(send_buf), 0); //第 4 步 向套接字中写入字符串
    }*/
    return NULL;  
}

void open_dev()
{
    fd = open("/dev/dsx", O_RDWR);
    if(fd < 0)
        printf("/dev/dsx is open fail!\n");
}

int main(int argc, char *argv[])
{
    int client_sockfd;
    int len;
    struct sockaddr_in remote_addr; //服务器端网络地址结构体
    char buf[BUFSIZ];  //数据传送的缓冲区
    memset(&remote_addr,0,sizeof(remote_addr)); //数据初始化--清零
    remote_addr.sin_family=AF_INET; //设置为IP通信
    remote_addr.sin_addr.s_addr=inet_addr("0.0.0.0");//服务器IP地址
    remote_addr.sin_port=htons(8000); //服务器端口号
    open_dev();
    /*创建客户端套接字--IPv4协议，面向连接通信，TCP协议*/
    if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket");
        return 1;
    }

    /*将套接字绑定到服务器的网络地址上*/
    if(connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0)
    {
        perror("connect");
        return 1;
    }
    printf("connected to server\n");
    //len=recv(client_sockfd,buf,BUFSIZ,0);//接收服务器端信息
    //     buf[len]='\0';
    //printf("%s",buf); //打印服务器端信息
    //新建一个线程来进行发送操作.
    pthread_t ntid;
    pthread_create(&ntid,NULL,thread,&client_sockfd);
    /*循环的发送接收信息并打印接收信息--recv返回接收到的字节数，send返回发送的字节数*/
    while(1)
    {
        //printf("Enter string to send:");
        scanf("%s",buf);
        if(!strcmp(buf,"quit"))
            break;
        len=send(client_sockfd,buf,strlen(buf),0);
        //len=recv(client_sockfd,buf,BUFSIZ,0);
        //buf[len]='\0';
        //printf("received:%s\n",buf);
        printf("client:send ok.\n");
    }
    close(client_sockfd);//关闭套接字
        return 0;
}
