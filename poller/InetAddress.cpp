/*************************************************************************
	> File Name: InetAddress.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月07日 星期四 14时15分49秒
 ************************************************************************/

#include "InetAddress.h"
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

InetAddress::InetAddress(uint16_t port)
{
	::bzero(&addr_, sizeof(addr_));
	addr_.sin_family = AF_INET;
	addr_.sin_port = ::htons(port);
	addr_.sin_addr.s_addr = ::htonl(INADDR_ANY);
}

InetAddress InetAddress::getLocalAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	if(::getsockname(sockfd, (SA*)&addr, &len) == -1)
		ERR_EXIT("getsockname");
	return InetAddress(addr);
}

InetAddress InetAddress::getPeerAddress(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	if(::getpeername(sockfd, (SA*)&addr, &len) == -1)
		ERR_EXIT("getpeername");
	return InetAddress(addr);
}

