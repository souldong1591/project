/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 14时58分16秒
 ************************************************************************/

#include "net.h"
#include <sys/epoll.h>

int get_listen_fd();
void do_epoll(int listenfd);


int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");

	int listenfd = get_listen_fd();

	do_epoll(listenfd);

	close(listenfd);
	return 0;
}

int get_listen_fd()
{
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
		ERR_EXIT("socket");
	
	int on = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(8989);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
		ERR_EXIT("bind");

	if(listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	return listenfd;
}

void do_epoll(int listenfd)
{
	int epollfd = epoll_create(2048);
	if(epollfd == -1)
		ERR_EXIT("epoll_create");
	struct epoll_event ev;
	ev.data.fd = listenfd;
	ev.events = EPOLLIN;
	if(epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev) == -1)
		ERR_EXIT("epoll_ctl");

	struct epoll_event events[2048];
	int nready;
	while(1)
	{
		nready = epoll_wait(epollfd, events, 2048, -1);
		if(nready == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("epoll_wait");
		}

		int i;
		for (i = 0; i < nready; i++) 
		{
			if(events[i].data.fd == listenfd)
			{
				int peerfd = accept(listenfd, NULL, NULL);
				if(peerfd == -1)
					ERR_EXIT("accept");

				struct epoll_event ev;
				ev.data.fd = peerfd;
				ev.events = EPOLLIN;
				if(epoll_ctl(epollfd, EPOLL_CTL_ADD, peerfd, &ev) == -1)
					ERR_EXIT("epoll_ctl");

			}
			else
			{
				int peerfd = events[i].data.fd;
				char recvbuf[1024] = "";
				int ret = readline(peerfd, recvbuf, 1024);
				if(ret == -1)
					ERR_EXIT("readline");
				else if(ret == 0)
				{
					printf("client close\n");
					struct epoll_event ev;
					ev.data.fd = peerfd;
					if(epoll_ctl(epollfd, EPOLL_CTL_DEL, peerfd, &ev) == -1)
						ERR_EXIT("epoll_ctl");
					close(peerfd);
					continue;
				}

				printf("recv data: %s", recvbuf);
				writen(peerfd, recvbuf, strlen(recvbuf));
			}
		}
	}
	close(epollfd);
}
