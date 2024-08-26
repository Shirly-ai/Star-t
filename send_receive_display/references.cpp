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
#include <arpa/inet.h>//大小字节转化
int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
  struct sockaddr_in servaddr;//为了让bind()绑定IP和端口号而定义的
  bzero(&serv_addr, sizeof(serv_addr));//将网络地址清空
  servaddr.sin_family = AF_INET;//与socket()的第一个参数 int domain一样的协议
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//绑定IP
  servaddr.sin_port = htons(6666);//绑定端口号
//h:host表示主机字节序（小端字节序）；n:network表示网络字节序（大端字节序）；l:long32位长整型；s:short16位短整型
//输入ip和端口后，计算机会自动处理成小字节，于是用htons/l转化为大字节。
  bind(serv_addr, (struct sockaddr*)&serv_addr, sizeof(serv_addr））;
//成功:返回 0
//失败:返回 -1

/*
#include <arpa/inet.h>
//主机字节序(小端字节序)转换成网络字节序(大端字节序)
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);

//网络字节序(大端字节序)转换成主机字节序(小段字节序)
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

*/


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
第一个参数： const char *path：
				文件名的字符串地址
第二个参数： int flag：
				文件打开模式
返回值：
		成功：返回文件描述符
		失败：-1
//文件打开模式：
//O_CREAT 必要时创建文件
//O_TRUNC 删除全部现有数据
//O_APPEND 维持现有数据 保存到其后面
//O_RDONLY 只读打开
//O_WRONLY 只写打开
//O_RDWR 读写打开

#include<unistd.h>
int close(int fd);
//fd:需要关闭的文件或套接字的文件描述符
成功:返回 0 
失败:返回 -1

#include<unistd.h>
ssize_ write(int fd, const void *buf, size_t nbytes);
//fd:显示数据传输对象的文件描述符
//const void *buf:保存要传输数据的缓冲地址值
//nbytes:要传数据的字节数
成功:返回写入的字节数
失败:返回 -1

#include<unistd.h>
ssize_t read(int fd, void *buf, size_t nbytes);
//fd:显示数据接收对象的文件描述符
//*buf:保存接收数据的缓冲地址值
//nbytes:要接收数据的最大字节数
成功:返回接受的字节数(但遇到文件结尾则返回 0 )
失败：-1
