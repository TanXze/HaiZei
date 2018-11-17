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

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int sock_server, sockfd;
char buffer[BUFFER_SIZE];
struct sockaddr_in server_addr, client_addr;

int main(int argc, char *argv[]) {
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind");
        return -1;
    }

    if (listen(sockfd, 20) < 0) {
        perror("Listen");
        return -1;
    }
    int port = atoi(argv[1]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int sock_listen = sock_server;
    pid_t pid;
    int n, x, y;
    scanf("%d", &n);
    x = n % 5;
    if (x == 0) {
	y = n / 5;
    } else {
	y = n / 5 + 1;
    }
    while (1) {
        for (int i = 0; i < 5; i++) {
            pid = fork();
            if (pid == 0 || pid == -1) break;
	    exit(0);
        }
        if (pid == -1) {
            printf("Fork() Error\n");
        } else if (pid == 0) {
            for (int j = 0; j < y; j++) { 
		socklen_t size = sizeof(client_addr);
        	sock_server = accept(sock_listen, (struct sockaddr *) &client_addr, &size);
        	if (sock_server < 0) {
                    perror("Accept");
            	    break;
        	}

        	struct sockaddr_in peer;
        	socklen_t len = sizeof(peer);
        	bzero(&peer, sizeof(peer));
        	getpeername(sock_server, (struct sockaddr *) &peer, &len);
        	char buff_peer[64] = {'\0'};
        	inet_ntop(AF_INET, (void *)&peer.sin_addr, buff_peer, 63);
        	printf("%s已连接:\n", buff_peer);	        
            }
        }
	close(sock_server);
    }
    return 0;
}
