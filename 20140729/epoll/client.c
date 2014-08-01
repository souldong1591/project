/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月29日 星期二 15时43分02秒
 ************************************************************************/

#include "net.h"
#include <sys/epoll.h>

void do_client(int peerfd)
{
	char recv_buf[1024] = "";
	char send_buf[1024] = "";
	
	int epollfd = epoll_create(2);
	if(epollfd == -1)
		ERR_EXIT("epoll_create");

	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = STDIN_FILENO;
	if(epoll_ctl(epollfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1)
		ERR_EXIT("epoll_ctl");

	ev.events = EPOLLIN;
	ev.data.fd = peerfd;
	if(epoll_ctl(epollfd, EPOLL_CTL_ADD, peerfd, &ev) == -1)
		ERR_EXIT("epoll_ctl");


	struct epoll_event events[2];
	int nready;

	while(1)
	{
		nready = epoll_wait(epollfd, events, 2, -1);
		if(nready == -1)
		{
			if(errno = EINTR)
				continue;
			ERR_EXIT("epoll_wait");
		}
		else if(nready == 0)
			continue;

		int i;
		for (i = 0; i < nready; i++) 
		{
			int fd = events[i].data.fd;
			if(fd == STDIN_FILENO)
			{
				if(fgets(send_buf, 1024, stdin) == NULL)
				{
					shutdown(peerfd, SHUT_WR);
					struct epoll_event ev;
					ev.data.fd = STDIN_FILENO;
					if(epoll_ctl(epollfd, EPOLL_CTL_DEL, STDIN_FILENO, &ev) == -1)
						ERR_EXIT("epoll_ctl");
				}
				else
					writen(peerfd, send_buf, strlen(send_buf));
				
			}

			if(fd == peerfd)
			{
				int ret = readline(peerfd, recv_buf, 1024);
				if(ret == -1)
					ERR_EXIT("readline");
				else if(ret == 0)
				{
					close(peerfd);
					printf("server close\n");
					exit(EXIT_SUCCESS);
				}
				
				printf("recv data: %s\n", recv_buf);
			}
		}
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
    


    do_client(peerfd);


    close(peerfd);

    return 0;
}

