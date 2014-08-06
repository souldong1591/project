/*************************************************************************
	> File Name: EpollPoller.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 20时37分22秒
 ************************************************************************/

#include <unistd.h>
#include <errno.h>
#include <iostream>
#include "EpollPoller.h"
#include "net.h"
using namespace std;
EpollPoller::EpollPoller(int listenfd, const HandleCallback &callback)
	:listenfd_(listenfd),
	 nready_(0)
{
	if((epollfd_ = epoll_create(2048) == -1))
		ERR_EXIT("epoll_create");
	add_fd(listenfd_);
	callback_ = callback;
}

EpollPoller::~EpollPoller()
{
	close(epollfd_);
	close(listenfd_);
}

void EpollPoller::do_wait()
{
	int nready;
	do
	{
		nready = epoll_wait(epollfd_, events_, 2048, -1);
	}while(nready == -1 && errno == EINTR);

	if(nready == -1)
		ERR_EXIT("epoll_wait");
	nready_ = nready;
}

void EpollPoller::handle_accept()
{
	int peerfd = accept(listenfd_, NULL, NULL);
	if(peerfd == -1)
		ERR_EXIT("accept");
	cout << "client on" << endl;
	add_fd(peerfd);
}

void EpollPoller::handle_data(int peerfd)
{
	char recvbuf[1024];
	int ret = readline(peerfd, recvbuf, 1024);
	if(ret == -1)
		ERR_EXIT("readline");
	else if(ret == 0)
	{
		cout << "client close" << endl;
		del_fd(peerfd);
		return;
	}
	bind(&callback_, peerfd, recvbuf);
}

void EpollPoller::handle()
{
	for (int i = 0; i < nready_; i++)
	{
		int fd = events_[i].data.fd;
		if(fd == listenfd_)
			handle_accept();
		else
			handle_data(fd);
	}
}

void EpollPoller::add_fd(int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(epoll_ctl(epollfd_, EPOLL_CTL_ADD, fd, &ev) == -1)
		ERR_EXIT("epoll_ctl");
}

void EpollPoller::del_fd(int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	if(epoll_ctl(epollfd_, EPOLL_CTL_DEL, fd, &ev) == -1)
		ERR_EXIT("epoll_ctl");
}
