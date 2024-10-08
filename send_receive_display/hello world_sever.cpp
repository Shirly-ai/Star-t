#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char *argv[]) {
	//为了接收套接字而定义
	int serv_sock;
	int clnt_sock;

	//要保存的IP、端口号、长度
	struct sockaddr_in serv_addr;
	struct aockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";

	//？
	if (argc != 2) {
		printf("Usage:%s <port>\n", argv[0]);
		exit(1);
	}

	//成为套接字
	serv_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1) {
		error_handling("socket() error");
	}

	//咔咔写
	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(argv[1]);
	if (bind(serv_sock, (struct sockaddr *)&serv_addr), sizeof(serv_addr) == -1) {
		error_handling("bind() error");
	}

	if (listen(serv_sock, 5) == -1) {
		error_handling("listen() error");
	}

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1) {
		error_handling("accept() error");
	}

	write(clnt_sock, message, sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr); //把message写入stderr，stderr是文件的指针
	fputc('\n', stderr); //将\n写入文件流，并把位置标识符往前移动一位
	exit(1);
}
