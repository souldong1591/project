/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月28日 星期一 17时05分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


ssize_t readn(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n; //表示还需要读取的字节数
    ssize_t nread;
    char *bufp = usrbuf; //控制read函数存放的位置

    while(nleft > 0)
    {
        if((nread = read(fd, bufp, nleft)) == -1)
        {
            if(errno == EINTR)  //interupt
                nread = 0;  //continue;  中断需要再次读取
            else
                return -1;  // ERROR
        }else if(nread == 0)  // EOF
            break;
        
        nleft -= nread;
        bufp += nread;
    }
    return (n - nleft);
}

ssize_t writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;

    char *bufp = usrbuf;

    while(nleft > 0)
    {
        //nwrite == 0也属于错误
        if((nwrite = write(fd, bufp, nleft)) <= 0)
        {
            if(errno == EINTR)
                nwrite = 0;
            else
                return -1; // -1 和 0
        }

        nleft -= nwrite;
        bufp += nwrite;
    }
    return n;  //这里不是 n- nleft 必须是n
}


ssize_t readline(int fd, void *usrbuf, size_t maxlen)
{
    char *bufp = usrbuf;  //记录缓冲区当前位置
    ssize_t nread;
    size_t nleft = maxlen - 1;  //留一个位置给 '\0'
    char c;
    while(nleft > 0)
    {
        if((nread = read(fd, &c, 1)) < 0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }else if(nread == 0) // EOF
        {
            break;
        }

        //普通字符
        *bufp++ = c;
        nleft--;

        if(c == '\n')
            break;
    }
    *bufp = '\0';
    return (maxlen - nleft - 1);
}

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    while(1)
    {
        int ret;
        //fgets吸收的字符串以\n作为结尾
        if(fgets(sendbuf, 1000, stdin) != NULL)
        {
            writen(peerfd, sendbuf, strlen(sendbuf));

            ret = readline(peerfd, recvbuf, 1024);
            if(ret == 0)
                break;

            printf("receive data : %s", recvbuf);
        }
        
        memset(sendbuf, 0, sizeof sendbuf);
        memset(recvbuf, 0, sizeof recvbuf);
    }

}




int main(int argc, const char *argv[])
{
    //创建socket
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("socket");


    //connect
    struct sockaddr_in peeraddr;
    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port = htons(8989);
    peeraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(peerfd, (struct sockaddr *)&peeraddr, sizeof peeraddr) < 0)
        ERR_EXIT("connect");
    


    do_service(peerfd);


    close(peerfd);

    return 0;
}

