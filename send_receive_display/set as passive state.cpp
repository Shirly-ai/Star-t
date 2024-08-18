//listen函数把进程变为一个服务器（将主动连接套接口变为被连接套接口，使得一个进程可以接受其他进程的请求）
//int listen(int sockfd,int backlog)
#include<cstdio>
#include<sys/types.h>
#include<sys/socket.h>
#include<cstdlib>
#include<netinet/in.h>
#include<cstring>
int main()
{
	int sockfd,bind_fd,listen_fd;
	struct sockaddr_in sercaddr;
	
	//建立
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		perror("create socket fail\n");
		exit(1);
	}
	else
	printf("create success\n");
	
	//初始化
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INEF;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(2500);
	
	//绑定端口
	bind_fd=bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(bind_fd==-1)
	{
		perror("bind fail\n");
		exit(1);
	}
	else
	printf("bind success\n");
	
	//将已绑定的套接口设为被动连接监听
	listen_fd=listen(sockfd,10);//内核维护一个队列来跟踪·完成连接但是服务器没有接手处理/正在进行的连接，队列大小为10
	if(listen_fd==-1)
	{
		perror("listen fail\n");
		exit(1);
	}
	else
	{
		printf("listen success\n");
	}
	close(sockfd);
	return 0;
}
