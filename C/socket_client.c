/*************************************************************************
	> File Name: socket_1.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年09月23日 星期日 16时56分34秒
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>		
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>

#define MAX_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char *argv[]) {
    int sock_client;
    char buffer[MAX_SIZE];
    struct sockaddr_in server_addr;
    int port = atoi(argv[2]);
    char *host = argv[1];
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock_client, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect");
        return -1;
    }
    printf("Connect success!\n");

    /*while (1) {
        scanf("%[^\n]s", buffer);
        getchar();
        send(sock_client, buffer, strlen(buffer), 0);
    }*/

    char file_name[FILE_NAME_MAX_SIZE + 1];
	char file_name_save[FILE_NAME_MAX_SIZE + 1];
	bzero(file_name, FILE_NAME_MAX_SIZE + 1);
	printf("Please Input File Name On Server:\t");
	scanf("%s", file_name);

	char buffer[BUFFER_SIZE];
	bzero(buffer, BUFFER_SIZE);
	strncpy(buffer, file_name, strlen(file_name)>BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));

	// 向服务器发送buffer中的数据
	if (send(client_socket_fd, buffer, BUFFER_SIZE, 0) < 0)
	{
		perror("Send File Name Failed:");
		exit(1);
	}

	//输入要保存的地址
	printf("Please Input File Name to Save:\t");
	scanf("%s", file_name_save);

	// 打开文件，准备写入
	FILE *fp = fopen(file_name_save, "w");
	if (NULL == fp)
	{
		printf("File:\t%s Can Not Open To Write\n", file_name_save);
		exit(1);
	}

	// 从服务器接收数据到buffer中
	// 每接收一段数据，便将其写入文件中，循环直到文件接收完并写完为止
	bzero(buffer, BUFFER_SIZE);
	int length = 0;
	while ((length = recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) > 0)
	{
		if (fwrite(buffer, sizeof(char), length, fp) < length)
		{
			printf("File:\t%s Write Failed\n", file_name);
			break;
    }
		bzero(buffer, BUFFER_SIZE);
	}

	// 接收成功后，关闭文件，关闭socket 
	printf("Receive File:\t%s From Server IP Successful!\n", file_name);
	close(fp);
	close(client_socket_fd);
	return 0;
}


//谭小泽
