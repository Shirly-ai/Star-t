#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message)

int main(int argc, char *argv[]) {
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;

	if (argc != 3) { //?
		printf("Usage:%s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		error_handling("socket() error");
	}

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2])); //atoi()转换字符串的函数

	if (connet(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
		error handling("connect() error");
	}

	str_len = read(sock, message, sizeof(message) - 1); //message里面包括\0
	if (str_len == -1) {
		error_handling("read() error");
	}

	printf("Message from sever:%s \n", message);
	close(sock);
	return 0;
}

void error_handling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
