#include<sys/socket.h>
int socket(int domain, int type, int protocol);
  domain:协议族
    IPv4:AF_INET
    IPv6:AF_INET6
  type:协议
    TCP:SOCK_STREAM
    UDP:SOCK_DGRAM
  protocol:应用层自定义协议（可暂时默认为0）
//成功:返回文件描述符
//失败:返回 -1

#include<sys/socket.h>
int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
//成功:返回 0
//失败:返回 -1

#include<sys/socket.h>	
int listen(int sockfd, int backlog);
成功:返回 0
失败:返回 -1

#include<sys/socket.h>
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
成功:返回文件描述符
失败:返回-1

#include<sys/socket.h>
int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
成功:返回 0
失败:返回 -1


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int open(const char *path, int flag);
成功:返回文件描述符
失败:返回 -1

#include<unistd.h>
int close(int fd);
成功:返回 0 
失败:返回 -1

#include<unistd.h>
ssize_ write(int fd, const void *buf, size_t nbytes);
成功:返回写入的字节数
失败:返回 -1

#include<unistd.h>
ssize_t read(int fd, void *buf, size_t nbytes);
成功:返回接受的字节数(但遇到文件结尾则返回 0 )
