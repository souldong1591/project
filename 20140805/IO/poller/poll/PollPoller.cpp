/*************************************************************************
	> File Name: PollPoller.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 17时26分53秒
 ************************************************************************/

#include "PollPoller.h"
#include "net.h"
#include <errno.h>
#include <iostream>
#include <unistd.h>
#include <assert.h>

using namespace std;

PollPoller::PollPoller(int listenfd)
	:max_(0),
	 nready_(0)
{
	for (int i = 0; i < 2048; i++)
	{
		clients_[i].fd = -1;
	}
	clients_[0].fd = listenfd;
	clients_[0].events = POLLIN;
}

PollPoller::~PollPoller()
{}

void PollPoller::do_wait()
{
	int nready;
	do
	{
		nready = poll(clients_, max_ + 1, -1);
	}while(nready == -1 && errno == EINTR);

	if(nready == -1)
		ERR_EXIT("poll");
	nready_ = nready;
}

void PollPoller::handle_accept()
{
	if(clients_[0].revents & POLLIN)
	{
		int peerfd = accept(clients_[0].fd, NULL, NULL);
		if(peerfd == -1)
			ERR_EXIT("accept");
		cout << "client on" << endl;
		add_fd(peerfd);
	}
	
}

void PollPoller::handle_data()
{
	for (int i = 1; i <= max_; i++)
	{
		int fd = clients_[i].fd;
		if(fd == 1)
			continue;
		if(clients_[i].revents & POLLIN)
		{
			char recvbuf[1024] = "";
			int ret = readline(fd, recvbuf, 1024);
			if(ret == -1)
				ERR_EXIT("readline");
			else if(ret == 0)
			{
				del_fd(i);	
				cout << "client close" << endl;
				continue;
			}
			bind(&callback_, fd, recvbuf);
		}
	}
}

void PollPoller::add_fd(int fd)
{
	int i;
	for (i = 0; i < 2048; i++) 
	{
		if(clients_[i].fd == -1)
		{
			clients_[i].fd = fd;
			clients_[i].events = POLLIN;
			if(i > max_)
				max_ = i;
			break;
		}
	}
	if(i == 2048)
	{
		fprintf(stderr, "too many client\n");
		exit(EXIT_FAILURE);
	}
}

void PollPoller::del_fd(int i)
{
	assert(i >= 1 && i < 2048);
	close(clients_[i].fd);
	clients_[i].fd = -1;
	
}
