/*************************************************************************
	> File Name: Rio.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 22时08分57秒
 ************************************************************************/

#include "Rio.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

Rio::Rio(int fd)
	:fd_(fd),
	 left_(0),
	 bufptr_(buffer_)
{}

Rio::~Rio()
{
	::close(fd_);
}

ssize_t Rio::rio_read(char *usrbuf, size_t n)
{
	ssize_t nread;
	while(left_ <= 0)
	{
		if((nread = ::read(fd_, buffer_, sizeof(buffer_))) == -1)
		{	
			if(errno == EINTR)
				continue;
			return -1;
		}
		else if(nread == 0)
			return 0;
		left_ = nread;
		bufptr_ = buffer_;
	}

	int cnt = n;
	if(left_ < n)
		cnt = left_;
	::memcpy(usrbuf, bufptr_, cnt);
	left_ -= cnt;
	bufptr_ += cnt;
	return cnt;
}

ssize_t Rio::rio_readn(char *usrbuf, size_t n)
{
	ssize_t nread;
	size_t nleft = n;
	char *bufp = usrbuf;
	while(nleft > 0)
	{
		if((nread = rio_read(bufp, nleft)) == -1)
			return -1;
		else if(nread == 0)
			return 0;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}

ssize_t Rio::rio_writen(const char *usrbuf, size_t n)
{
	ssize_t nwrite;
	size_t nleft = n;
	const char *bufp = usrbuf;
	while(nleft > 0)
	{
		if((nwrite = write(fd_, bufp, nleft)) <= 0)
		{
			if(errno == EINTR)
				nwrite = 0;
			else
				return -1;
		}
		nleft -= nwrite;
		bufp += nwrite;
	}
	return n;
}

ssize_t Rio::rio_readLine(char *usrbuf, size_t maxlen)
{
	char *bufp = usrbuf;
	char c;
	ssize_t nread;
	int i;
	for (i = 0; i < maxlen - 1; i++) 
	{
		if((nread = rio_read(&c, 1)) == -1)
			return -1;
		else if(nread == 0)
		{
			if(i == 0)
				return 0;
			break;
		}
		*bufp++ = c;
		if(c == '\n')
			break;
	}
	*bufp = '\0';
	return i;
}
