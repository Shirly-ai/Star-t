//利用bind函数将创建好的套接字绑定到本地计算机的某一端口上
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>

int main() {
	int sockfd, bind_fd;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("create socket fail\n");
		exit(1);
	} else
		printf("create success\n");

	//初始化
	bzero(&servaddr, sizeof(servaddr)); //结构体初始化
	servaddr.sin_family = AF_INET; //确定IP协议
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //接受任意IP
	servaddr.sin_port = htons(2500); //设定端口号2500

	//绑定端口！！
	bind_fd = bind(sockfd, (stuct sockaddr *)&servaddr, sizeof(servaddr));
	if (bind_fd == -1) {
		perror("bind fail\n");
		exit(1);
	} else
		printf("bind success\n");

	close(sockfd);
	return 0;
}
