
#include "head.h"

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char *argv[]) {
    int sock_client, sockfd;
    struct sockaddr_in dest_addr;
    if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;        
    }

    int port = atoi(argv[2]);
    char *host = argv[1];
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sock_client, (struct sockaddr * ) & dest_addr, sizeof(dest_addr))) {
        perror("Connect");
	    return -1;            
    }
    printf("Connect Master Success!\n");

    while (1) {
        if ((bind(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr))) < 0) {
            perror("bind() error!\n");
            return -1;
        }

        if (listen(sockfd, 20) < 0) {
            perror("listen() error!\n");
            return -1;
        }
    }
}
