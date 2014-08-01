/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 14时58分16秒
 ************************************************************************/

#include "net.h"
#include <poll.h>

int get_listen_fd();
void do_poll(int listenfd);


int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");

	int listenfd = get_listen_fd();

	do_poll(listenfd);

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

void do_poll(int listenfd)
{
	struct pollfd client[2048];
	int i;
	for (i = 0; i < 2048; i++) 
	{
		client[i].fd = -1;
	}

	client[0].fd = listenfd;
	client[0].events = POLLIN;

	int max = 0;
	int nready;
	while(1)
	{
		nready = poll(client, max + 1, -1);
		if(nready == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("poll");
		}
		else if(nready == 0)
			continue;

		if(client[0].revents & POLLIN)
		{
			int peerfd = accept(client[0].fd, NULL, NULL);
			if(peerfd == -1)
				ERR_EXIT("accept");
			int i;
			for (i = 0; i < 2048; i++) 
			{
				if(client[i].fd == -1)
				{
					client[i].fd = peerfd;
					client[i].events = POLLIN;
					if(i > max)
						max = i;
					break;
				}
			}

			if(i == 2048)
			{
				fprintf(stderr, "to many client\n");
				exit(EXIT_FAILURE);
			}

			if(--nready <= 0)
				continue;
		}

		int i;
		for (i = 0; i <= max; i++) 
		{
			int fd = client[i].fd;
			if(fd == -1)
				continue;
			if(client[i].revents & POLLIN)
			{
				char recvbuf[1024] = "";
				int ret = readline(fd, recvbuf, 1024);
				if(ret == -1)
					ERR_EXIT("readline");
				else if(ret == 0)
				{
					close(fd);
					client[i].fd = -1;
					continue;
				}
				
				printf("recv data: %s", recvbuf);
				writen(fd, recvbuf, strlen(recvbuf));

				if(--nready <= 0)
					break;
			}
		}
	}
}
