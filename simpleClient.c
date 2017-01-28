#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(void){
    //socket对象
    int sockfd;
    //socket地址长度
    int len;
    //socket地址（ipv4）
    struct sockaddr_in address;
    //socket链接结果
    int result;
    //传送字符
    char ch = 'A';

    //申请一个socket
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    //填充socket地址
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(9734);
    //得到address长度
    len = sizeof(address);
    
    //开始链接
    result = connect(sockfd,(struct sockaddr*)&address,len);
    //链接出错打印
    if(result == -1){
       perror("客户端链接失败!");
       exit(1);
    }

    //服务器端写一个字符
    write(sockfd,&ch,1);
    //服务器写读一个字符
    read(sockfd,&ch,1);
    //打印读到的字符
    printf("从服务器得到的字符是:%c\n",ch);
    //关闭socket
    close(sockfd);
    //成功退出
    exit(0);
}
