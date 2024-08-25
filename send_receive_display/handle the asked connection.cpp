//accept函数处理客户端请求的连接
//accept(int sockfd,struct sockaddr* addr,)
//sockfd:监听套接字
//addr:指定客户端地址的返回值（NULL）
//len:addr结构体发大小（NULL）
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MYPORT 3490

int main() {
	int sockfd, newfd, listen_fd, bind_fd;
	char buf[100];
	socklen_t len;
	struct sockaddr_in servaddr;//服务器
	struct sockaddr_in clientaddr;//客户端

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket error\n");
		exit(1);
	} else {
		printf("create socket successful\n");
	}

	servaddr.sin_family = AF_INET; //确定IP协议
	servaddr.sin_port = htons(MYPORT); //设定端口号
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //接受任意IP
	bzero(&(servaddr.sin_zero), 8); //结构体初始化

	bind_fd = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if (bind_fd == -1) {
		perror("bind error\n");
		exit(1);
	} else {
		printf("bind successful\n");
	}

	listen_fd = listen(sockfd, 10);
	if (listen_fd == -1) {
		perror("listen error\n");
		exit(1);
	} else {
		printf("listen successful\n");
	}

	while(1)
	{
		len=sizeof(clientaddr);
		newfd=accept(sockfd,(struct sockaddr*)&clientaddr,&len);
		if(newfd==-1)
		{
			perror("accept error\n");
			exit(1);
		}
		else
		{
			printf("accept successful\n");
		}
		if(inet_ntop(AF_INET,&clientaddr.sin_addr,buf,,sizeof(buf)==NULL))//转化为本地可识别ip
		{
			perror("inet_ntop error\n");
			exit(1);
		}
		printf("conneting from %s ,",buf);//字符串型格式符
		printf("port is %d\n",ntohs(clientaddr.sin_port));//%d表示由十进制整数型输出
		close(newfd);//close?	
	}
	close(sockfd);
	return 0;
}
