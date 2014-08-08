/*************************************************************************
	> File Name: PollPoller.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月06日 星期三 15时43分18秒
 ************************************************************************/

#include "PollPoller.h"
#include <assert.h>
#include <iostream>
#include <errno.h>

using namespace std;

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

PollPoller::PollPoller(int listenfd)
	:listenfd_(listenfd),
	 maxi_(0),
	 nready_(0)
{
	for (int i = 0; i < 2048; i++)
		event_[i].fd = -1;
	event_[0].fd = listenfd_;
	event_[0].events = POLLIN;		
}

void PollPoller::poll()
{
	int ret;
	do
	{
		ret = ::poll(event_, maxi_ + 1, 10000);
	}while(ret == -1 && errno == EINTR);
	if(ret == -1)
		ERR_EXIT("poll");
	nready_ = ret;
}

void PollPoller::handleAccept()
{
	if(event_[0].revents & POLLIN)
	{
		int peerfd = ::accept(listenfd_, NULL, NULL);
		if(peerfd == -1)
			ERR_EXIT("accept");
		handleConnectionEvent(peerfd);
	}
}

void PollPoller::handleData()
{
	for (int i = 1; i <= maxi_; i++)
	{
		int peerfd = event_[i].fd;
		if(peerfd == -1)
			continue;
		if(event_[i].revents & POLLIN)
		{
			char buf[1024] = "";
			int nread = recv(peerfd, buf, sizeof(buf), MSG_PEEK);
			if(nread == -1)
				ERR_EXIT("recv");
			else if(nread == 0)
				handleCloseEvent(i);
			else
				handleMessageEvent(peerfd);
		}
	}
}

void PollPoller::handleConnectionEvent(int peerfd)
{
	int i;
	for (i = 1; i < 2048; i++) 
	{
		if(event_[i].fd == -1)
		{
			event_[i].fd = peerfd;
			event_[i].events = POLLIN;
			if(i > maxi_)
				maxi_ = i;
			break;
		}
	}

	if(i == 2048)
	{
		::fprintf(stderr, "too many clients\n");
		exit(EXIT_FAILURE);
	}

	TcpConnectionPtr conn(new TcpConnection(peerfd, InetAddress::getLocalAddress(peerfd), InetAddress::getPeerAddress(peerfd)));

	conn->setConnectionCallback(onConnectionCallback_);
	conn->setMessageCallback(onMessageCallback_);
	conn->setCloseCallback(onCloseCallback_);

	pair<TcpIterator, bool> ret = lists_.insert(make_pair(peerfd, conn));
	assert(ret.second == true);
	conn->handleConnection();
	//onConnectionCallback_(conn);
}

void PollPoller::handleMessageEvent(int peerfd)
{
	TcpIterator it = lists_.find(peerfd);
	assert(it != lists_.end());
	//onMessageCallback_(it -> second);
	it->second->handleMessage();
}

void PollPoller::handleCloseEvent(int i)
{
	assert(i >= 0 && i < 2048);
	int peerfd = event_[i].fd;
	assert(peerfd != -1);
	event_[i].fd == -1;
	TcpIterator it = lists_.find(peerfd);
	assert(it != lists_.end());
	//onCloseCallback_(it->second);
	it->second->handleClose();
	lists_.erase(it);
}


void PollPoller::setConnectionCallback(const PollerCallback &cb)
{
	onConnectionCallback_ = cb;
}

void PollPoller::setMessageCallback(const PollerCallback &cb)
{
	onMessageCallback_ = cb;
}

void PollPoller::setCloseCallback(const PollerCallback &cb)
{
	onCloseCallback_ = cb;
}

