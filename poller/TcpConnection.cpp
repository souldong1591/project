/*************************************************************************
	> File Name: TcpConnection.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月06日 星期三 15时08分04秒
 ************************************************************************/

#include "TcpConnection.h"

using namespace std;

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

TcpConnection::TcpConnection(int sockfd,
							 const InetAddress &localAddr,
							 const InetAddress &peerAddr)
	:sockfd_(sockfd),
	 buffer_(sockfd),
	 localAddr_(localAddr),
	 peerAddr_(peerAddr)
{}

TcpConnection::~TcpConnection()
{
	shutdown();
}

int TcpConnection::fd() const
{
	return sockfd_.fd();
}

ssize_t TcpConnection::readn(char *usrbuf, size_t n)
{
	int nread = buffer_.rio_readn(usrbuf, n);
	if(nread == -1)
		ERR_EXIT("readn");
	return nread;
}

ssize_t TcpConnection::readLine(char *usrbuf, size_t maxline)
{
	int nread = buffer_.rio_readLine(usrbuf, maxline);
	if(nread == -1)
		ERR_EXIT("readline");
	return nread;
}

ssize_t TcpConnection::writen(const char *usrbuf, size_t n)
{
	int nwrite = buffer_.rio_writen(usrbuf, n);
	if(nwrite == -1)
		ERR_EXIT("writen");
	return nwrite;
}

void TcpConnection::sendString(const std::string &s)
{
	writen(s.c_str(), s.size());
}

std::string TcpConnection::receiveString()
{
	char buf[1024];
	readLine(buf, 1024);
	return std::string(buf);
}

void TcpConnection::shutdown()
{
	sockfd_.shutdownWrite();
}
