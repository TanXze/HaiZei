#include "head.h"
#include "get_conf_value.c"

#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int main(int argc, char *argv[]) {
    int sock_client;
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
	close(sock_client);

	if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
		return -1;
    }
	char *connect_port = (char *)malloc(sizeof(char) * 5);
    get_conf_value("./piheadlthd.conf", "connect_port", connect_port);
    dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = atoi(connect_port);
    dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ((bind(sock_client, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr))) < 0) {
        perror("bind() error!\n");
        return -1;
    }

    if (listen(sock_client, 20) < 0) {
        perror("listen() error!\n");
        return -1;
    }

	int sock_listen = sock_client;
    while (1) {
		struct sockaddr_in master_addr;
        socklen_t len = sizeof(master_addr);
        if ((sock_client= accept(sock_listen, (struct sockaddr *)&master_addr, &len)) < 0) {
            perror("accept() error!\n");
            break;
        }
		printf("Master Connect Success!\n");
        close(sock_client);
	}
	close(sock_listen);
}
