//用socket创建一个网络套接字
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("create socket fail\n");
		exit(1);
	} else {
		printf("create success\n");
	}
	close(sockfd);
	return 0;
}
