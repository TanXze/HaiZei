/*************************************************************************
	> File Name: server.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月25日 星期二 11时03分32秒
 ************************************************************************/

#include <stdio.h>            //引入stdio.h头文件，这个头文件中包含了IO操作相关的函数
#include <stdlib.h>           //引入stdlib.h头文件，这个头文件中包含了一些类型和相关的通用函数
#include <string.h>           //引入string.h头文件，这个头文件中包含了字符串操作的相关函数
#include <errno.h>            //引入errno.h头文件，这个头文件中包含了错误处理的相关函数
#include <sys/socket.h>       //引入sys/目录下面的socket.h头文件，这个头文件中包含了套接字操作的相关函数
#include <sys/types.h>        //引入sys/目录下面的types.h头文件，这个头文件中包含了一些类型
#include <netinet/in.h>       //引入netinet/目录下面的in.h头文件，这个头文件中中包含了套接字地址结构体和本地地址和网络字节序列相互转换的相关的函数

int main(int argc, char* argv[])
{
    //定义要使用的相关边来------------------------------
    int ret;                                    //定义一个int类型的变量，来保存函数运行的结果
    int len;                                    //定义一个int类型的变量，来保存我们操作的字符串的相关数据
    int socket_server;                          //定义一个int类型的变量，这个变量用来保存服务端的套接字
    int socket_connect;                         //定义一个int类型的变量，这个变量用来保存客户端和服务端连接好了的套接字
    struct sockaddr_in server_address;          //定义一个sockaddr_in结构体，这个结构体用来保存服务端的地址相关的参数
    struct sockaddr_in client_address;          //定义一个sockaddr_in结构体，这个结构体用来保存接收到的客户端的地址相关的参数
    struct linger socket_exit;                  //定义一个linger结构体，这个结构体来确定套接子的退出的方式
    struct timeval socket_OT;                   //定义一个timeval结构体，这个结构体用来定义套接字的超时的时间
    char RecvBuffer[1024];                      //定义一个char类型的字符串，来保存函数函数接收到的数据
    char SendBuffer[1024];                      //定义一个char类型的字符串，来保存我们要发送的数据
    char* ptr;                                  //定义一个char*类型的指针用来转换字符串
	
    //初始化我们要使用的相关数据-----------------------
    memset(&server_address, 0x00, sizeof(server_address));
    memset(&client_address, 0x00, sizeof(client_address));
    memset(RecvBuffer, 0x00, sizeof(RecvBuffer));
    memset(SendBuffer, 0x00, sizeof(SendBuffer));
	
    //开始创建服务端套接字------------------------------
    socket_server = socket(AF_INET, SOCK_STREAM, 0);        //使用socket函数来创建一个套接字，这个套接字域为AF_INET，类型为流套接字
    if(socket_server < 0)                                   //如果socket_server < 0表示我们创建套接字失败
    {
        fprintf(stderr, "Create socket error, the error is %s\n", strerror(errno));    //输出错误的信息
        exit(EXIT_FAILURE);                                 //程序异常退出
    }

    server_address.sin_family = AF_INET;                    //为服务断套接字的地址设置属性，这个地址是AF_INET类型的地址
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);     //INADDR_ANY表示任意地址，指我们这个服务端可以接收任意地址的连接，并且使用htonl()将地址转换为网络字节序列
    server_address.sin_port = htons(12580);                 //设置我们服务端的监听的端口为12580，而且这个端口我们转换为网络字节序列
    ret = bind(socket_server, (struct sockaddr*)&server_address, sizeof(server_address));        //使用bind()函数将套接字和地址结构体绑定，从而为我们创建的套接字命名
    if(ret < 0)                                             //如果ret < 0表示我们的命名失败了
    {
        fprintf(stderr, "Bind error, The error is %s\n", strerror(errno));        //输出错误信息
        exit(EXIT_FAILURE);                                 //进程异常退出
    }
	
    //为套接字设置属性----------------------------------- 
    socket_exit.l_onoff = 0;                                //设置linger结构体中的l_onoff选项为0表示套接字要发送完数据再退出
    socket_OT.tv_sec = 60;                                  //设置timeval结构体中的tv_sec这个变量为60s
    socket_OT.tv_usec = 0;                                  //设置timeval结构体中的tv_usec这个变量为0us
	
    setsockopt(socket_server, SOL_SOCKET, SO_LINGER, &socket_exit, sizeof(socket_exit));    //设置套接字的退出方式
    setsockopt(socket_server, SOL_SOCKET, SO_RCVTIMEO, &socket_OT, sizeof(socket_OT));      //设置套接字的接收超时
    setsockopt(socket_server, SOL_SOCKET, SO_SNDTIMEO, &socket_OT, sizeof(socket_OT));      //设置套接字的发送超时
	
    //开始监听套接字，等待连接-------------------------
    ret = listen(socket_server, 1);                         //使用listen()函数来接受
    if(ret < 0)
    {
        fprintf(stderr, "listen error, The error is %s\n", strerror(errno));                //输出错误信息
        exit(EXIT_FAILURE);                                 //程序异常退出
    }
	
    //等待连接和操作套接字---------------------------
    int size = sizeof(client_address);                      //得到结构体的大小
    socket_connect = accept(socket_server, (struct sockaddr*)&client_address, &size);       //使用accpet()函数接受客户端的连接，&sizeof(XX)会报出单目运算符错误
    if(socket_connect < 0)                                  //socket_client < 0表示接受套接字失败
    {
        fprintf(stderr, "accpet error, The error is %s\n", strerror(errno));                //输出错误信息 
        exit(EXIT_FAILURE);                                 //进程异常退出
    }
    printf("accpet success!\n");
	//开始不断的接受数据---------------------------------
    while(1)
    {	
        len = recv(socket_connect, RecvBuffer, sizeof(RecvBuffer), 0);                      //使用recv()函数来接受客户端发送过来的数据
        if(len == 0)
        {
            printf("Connect Over--1!\n");                   //len为0的话，表示连接中断
            exit(EXIT_FAILURE);                             //进程异常退出
        }
        else if(len < 0)                                    //len < 0的话，表示连接失败
        {
            fprintf(stderr, "Recv error, the error is %s\n", strerror(errno));              //输出错误信息
            exit(EXIT_FAILURE);                             //进程错误退出
        }
        printf("%s\n", RecvBuffer);         //输出接收到的数据

        for(ptr = RecvBuffer; *ptr; ptr++)                  //将字符串中的数据转化为大写
        {
            *ptr = toupper(*ptr);										
        }
		
        strcpy(SendBuffer, RecvBuffer);                     //将变为大写的数据复制到SendBuffer中
        len = send(socket_connect, SendBuffer, strlen(SendBuffer), 0);                      //使用send()函数将处理完成的数据发送出去
        if(len == 0)
        {
            printf("Connect Over!--2\n");
            exit(EXIT_FAILURE);                             //进程异常退出
        }
        else if(len < 0)
        {
            fprintf(stderr, "Send error, the error is %s\n", strerror(errno));              //输出错误信息
            exit(EXIT_FAILURE);                             //程序异常退出
        }
        printf("We send %d bytes data, The data we send is %s\n", len, SendBuffer);         //输出信息
        printf("-----------------------------------------------------------------------\n");
        
        memset(RecvBuffer, 0x00, sizeof(RecvBuffer));       //重新清空RecvBuffer中的数据，一让下次接受没有上次接受的数据
    }
	
    close(socket_connect);                                  //关闭连接好的套接字
    printf("server will exit!\n");                          //输出信息
    exit(EXIT_SUCCESS);                                     //进程成功退出
}
