/*************************************************************************
	> File Name: poll_t.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月31日 星期四 14时54分39秒
 ************************************************************************/

#include "poll_t.h"

void poll_init(poll_t *pol, int listenfd)
{
	int i;
	for (i = 0; i < 2048; i++) 
	{
		pol->clients_[i].fd = -1;
	}
	pol->clients_[0].fd = listenfd;
	pol->clients_[0].events = POLLIN;
	pol->max_ = 0;

}

int poll_do_wait(poll_t *pol)
{
	int nready;
	do
	{
		nready = poll(pol->clients_, pol->max_ + 1, -1);
	}while(nready == -1 && errno == EINTR);
	if(nready == -1)
		ERR_EXIT("poll");
	pol->nready_ =  nready;
	return nready;
		
}

void poll_handle_accept(poll_t *pol)
{
	if(pol->clients_[0].revents & POLLIN)
	{
		int peerfd = accept(pol->clients_[0].fd, NULL, NULL);
		if(peerfd == -1)
			ERR_EXIT("accept");
		printf("client on\n");
		int i;
		for (i = 0; i < 2048; i++) 
		{
			if(pol->clients_[i].fd == -1)
			{
				pol->clients_[i].fd = peerfd;
				pol->clients_[i].events = POLLIN;
				if(i > pol->max_)
					pol->max_ = i;
				break;
			}
		}

		if(i == 2048)
		{
			fprintf(stderr, "too many client\n");
			exit(EXIT_FAILURE);
		}
	}
}

void poll_handle_data(poll_t *pol)
{
	int i;
	for (i = 1; i <= pol->max_; i++) 
	{
		int fd = pol->clients_[i].fd;
		if(fd == -1)
			continue;
		if(pol->clients_[i].revents & POLLIN)
		{
			char recvbuf[1024] = "";
			int ret = readline(fd, recvbuf, 1024);
			if(ret == -1)
				ERR_EXIT("readline");
			else if(ret == 0)
			{
				pol->clients_[i].fd = -1;
				close(fd);
				printf("client close\n");
				continue;
			}
			pol->handle_callback_(fd, recvbuf);
		}
	}
}

void poll_set_callback(poll_t *pol, void (*handle)(int, char *))
{
	pol->handle_callback_ = handle;
}
