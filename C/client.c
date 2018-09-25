/*************************************************************************
	> File Name: client.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月25日 星期二 11时06分00秒
 ************************************************************************/

#include <stdio.h>                    //引入stdio.h头文件，这个头文件中保存了Linux的相关的IO函数
#include <stdlib.h>                   //引用stdlib.h头文件，这个头文件中保存了5种类型和一些相通用函数
#include <string.h>                   //引入string.h头文件，这个头文件中保存了字符串操作的相关函数
#include <errno.h>                    //引入errno.h头文件，这个头文件中包含了错误操作相关的函数
#include <netinet/in.h>               //引入netinet/目录下面的in.h头文件，这个头文件中保存了套接字地址的相关结构体和网络字节序列转换的相关函数
#include <arpa/inet.h>				  //引入arpa/目录下面的inte.h头文件，这个头文件中保存了IP地址转换为网络字节序列的相关函数
#include <sys/types.h>                //引入sys/目录下面的types.h头文件，这个头文件中保存了一些基本的数据类型
#include <sys/socket.h>               //引入sys/目录下面的socket.h头文件，这个头文件中保存了套接子建立的相关函数

int main(int argc, char* argv[])
{
    //定义要使用的相关变量------------------------------
    int ret;                          //定义一个int类型的变量，来保存函数运行的结果
    int len;                          //定义一个int类型的变量，来记录我们操作的数据的长度
    int client_socket;                //定义一个int类型变量，来保存客户端建立起来的套接字
    char IP[20];                      //定义一个字符串来保存我们要连接的IP地址
    char RecvBuffer[1024];            //定义一个字符串来保存我们要接收的数据
    char SendBuffer[1024];            //定义一个字符串来保存我们要发送的数据
    struct sockaddr_in server_addr;   //定义一个sockaddr_in结构体，这个结构体的作用是用来保存客户端要连接的服务端套接子的相关地址信息
    struct linger socket_exit;        //定义一个linger结构体，这个结构体保存了套接字退出的方式
    struct timeval socket_OT;         //定义一个timeval结构体，这个结构体用来保存套接字发送超时的时间
	
    //对相关变量进行初始化------------------------------
    memset(IP, 0x00, sizeof(IP));                        //初始化保存IP的字符串数组
    memset(&socket_exit, 0x00, sizeof(socket_exit));     //初始化结构体
    memset(&socket_OT, 0x00, sizeof(socket_OT));         //初始化结构体
    memset(&server_addr, 0x00, sizeof(server_addr));     //对结构体先进行初始化
    memset(SendBuffer, 0x00, sizeof(SendBuffer));        //对保存发送数据的字符串进行初始化
    memset(RecvBuffer, 0x00, sizeof(RecvBuffer));        //对保存接收数据的数组进行初始化
	
    //开始创建套接字--------------------------------------
    if(argc != 2)                                        //参数不为2，表示我们要是连接本地地址
    {
        strcpy(IP, "127.0.0.1");                         //将本地地址保存到IP中
    }
    else
    {
        strcpy(IP, argv[1]);                             //如果参数为2，表示我们连接的IP地址为传给函数的一个参数
    }
    client_socket = socket(AF_INET, SOCK_STREAM, 0);     //使用socket()函数来建立一个未命名的套接字，这个套接字为IPv4网域的，类型为流套接字，协议使用默认协议
    if(client_socket < 0)                                //生成的套接字小于0表示socket()函数运行失败
    {
        fprintf(stderr, "socket create error! The error is %s\n", strerror(errno));        //向标准错误输出信息，套接字创建失败，并且输出错误信息
        exit(EXIT_FAILURE);                              //程序失败退出
    }

    server_addr.sin_family = AF_INET;                    //服务端地址协议族为AF_INET
    server_addr.sin_addr.s_addr = inet_addr(IP);         //服务端使用inet_addr()函数，将IP地址变为网络字节序列
    server_addr.sin_port = htons(12580);                 //服务端的监听的端口为12580将端口12580转化为网络字节序列

    //为套接字设置属性-----------------------------------
    socket_exit.l_onoff = 0;                             //设置linger结构体中的l_onoff选项为0表示套接字要发送完数据再退出
    socket_OT.tv_sec = 60;                               //设置timeval结构体中的tv_sec这个变量为60s
    socket_OT.tv_usec = 0;                               //设置timeval结构体中的tv_usec这个变量为0us

    setsockopt(client_socket, SOL_SOCKET, SO_LINGER, &socket_exit, sizeof(socket_exit));    //设置套接字的退出方式
    setsockopt(client_socket, SOL_SOCKET, SO_RCVTIMEO, &socket_OT, sizeof(socket_OT));      //设置套接字的接受超时时间
    setsockopt(client_socket, SOL_SOCKET, SO_SNDTIMEO, &socket_OT, sizeof(socket_OT));      //设置套接字的发送超时时间

    //使用我们建立好的套接字来连接远程服务端--------
    ret = connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));      //使用我们建立的套接字来连接客户端，如果没有连接成功他会阻塞一段时间
    if(ret < 0)
    {
        fprintf(stderr, "connect Error! The error is %s\n", strerror(errno));               //输出连接失败，并且输出错误信息
        exit(EXIT_FAILURE);                              //程序异常退出
    }
    printf("Connect to Server success!\n");              //如果程序没有异常退出，输出信息，连接到服务器成功

    //使用无限循环来发送和接受信息--------------------
    while(1)
    {
        //开始发送数据-------------------------------------
        printf("Please input the data you want send to the server!\n");
        printf("Input \"quit\" to quit!\n");
        fgets(SendBuffer, sizeof(SendBuffer), stdin);    //将我们要发送的数据写入到SendBuffer中，scanf()是要忽略空格的，所以这里使用的为fgets

        printf("The data we input is %s\n", SendBuffer);

        if(strncmp(SendBuffer, "quit", 4) == 0)          //如果输入的信息为q表示我们要退出客户端程序
        {
            printf("The client exit!\n");
            exit(EXIT_SUCCESS);                          //程序正常退出
        }
		
        len = send(client_socket, SendBuffer, strlen(SendBuffer), 0);         //使用send()函数来发出信息，注意这里使用的是strlen(SendBuffer)而不是sizeof(SendBuffer)
        if(len == 0)
        {
            printf("Connect Over!\n");
            exit(EXIT_FAILURE);                                               //进程异常退出
        }
        else if(len < 0)
        {
            fprintf(stderr, "Send error, The error is %s\n", strerror(errno));//输出错误信息
            exit(EXIT_FAILURE);                                               //程序异常终止
        }
        printf("We Send %d bytes data, The data we send is %s\n", len, SendBuffer);	//输出我们发送的数据的字节数，和我们发送的数据的实体
		
        //接受从服务端传回来的数据----------------------
        len = recv(client_socket, RecvBuffer, sizeof(RecvBuffer), 0);               //将服务器返回的数据保存到RecvBuffer中
        if(len == 0)
        {
            printf("Connect Over!\n");
            exit(EXIT_FAILURE);                          //进程异常退出
		}
        else if(len < 0)
        {
            fprintf(stderr, "Recv error, The error is %s\n", strerror(errno));      //输出错误信息
            exit(EXIT_FAILURE);                          //程序异常终止
        }
        printf("We Recv %d bytes data, The data we recv is %s\n", len, RecvBuffer);
        //close(client_socket);                                                     //关闭连接好的套接字，从而方便下一次使用，不能使用一个连接来重复发送数据，一个连接发送一次数据之后就不能再次使用了
        printf("-----------------------------------------------------------------------\n");
    }

    close(client_socket);                                //关闭连接好的套接字，从而方便下一次使用，不能使用一个连接来重复发送数据，一个连接发送一次数据之后就不能再次使用了
    printf("The socket is close! Programe exit!\n");     //输出信息
    exit(EXIT_SUCCESS);                                  //进程成功退出
}
