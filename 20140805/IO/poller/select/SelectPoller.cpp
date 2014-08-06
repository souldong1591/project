/*************************************************************************
	> File Name: Select.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 15时48分23秒
 ************************************************************************/

#include "SelectPoller.h"
#include "net.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <iostream>
using namespace std;

SelectPoller::SelectPoller(int listenfd, const HandleCallback &callback)
	:listenfd_(listenfd),
	 maxi_(-1),
	 maxfd_(listenfd_),
	 nready_(0)
{
	memset(client_, -1, FD_SETSIZE);
	FD_ZERO(&rset_);
	FD_ZERO(&allset_);
	FD_SET(listenfd_, &allset_);
	callback_ = callback;
}

SelectPoller::~SelectPoller()
{
	close(listenfd_);
}

void SelectPoller::do_wait()
{
	rset_ = allset_;
	int nready;
	do
	{
		nready = select(maxfd_ + 1, &rset_, NULL, NULL, NULL);
		
	}while(nready == -1 && errno == EINTR);
	if(nready == -1)
		ERR_EXIT("select");
	nready_ = nready;

}

void SelectPoller::handle_accept()
{
	if(FD_ISSET(listenfd_, &rset_))
	{
		int peerfd = accept(listenfd_, NULL, NULL);
		if(peerfd == -1)
			ERR_EXIT("accept");
		add_fd(peerfd);
	}
}

void SelectPoller::handle_data()
{
	for (int i = 0; i <= maxi_; i++)
	{
		if(FD_ISSET(client_[i], &rset_))
		{
			int peerfd = client_[i];
			char recvbuf[1024] = "";
			int ret = readline(peerfd, recvbuf, 1024);
			if(ret == -1)
				ERR_EXIT("readline");
			else if(ret == 0)
			{
				cout << "clinet close" << endl;
				del_fd(i);
				continue;
			}
			callback_(peerfd, recvbuf);
		}
	}
}

void SelectPoller::add_fd(int fd)
{
	int i;
	for (i = 0; i < FD_SETSIZE; i++)
	{
		if(client_[i] == -1)
		{
			client_[i] = fd;
			if(i > maxi_)
				maxi_ = i;
			break;
		}
	}

	if(i == FD_SETSIZE)
	{
		fprintf(stderr, "too many client\n");
		exit(EXIT_FAILURE);
	}

	FD_SET(fd, &allset_);
	if(fd > maxfd_)
		maxfd_ = fd;
}

void SelectPoller::del_fd(int i)
{
	assert(i >= 0 && i < FD_SETSIZE);
	int fd =  client_[i];
	client_[i] = -1;
	FD_CLR(fd, &allset_);
	close(fd);
}
