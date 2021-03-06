/*************************************************************************
	> File Name: 1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月24日 星期四 09时54分23秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

ssize_t readn(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;
	while(nleft > 0)
	{
		if((nread = read(fd, bufp, nleft)) == -1)
		{
			if(errno == EINTR)
			{
				nread = 0;
			}
			else
			{
				return -1;
			}
		}
		else if(nread == 0)
		{
			break;
		}
		
		nleft -= nread;
		bufp += nread;
	}

	return (n - nleft);
}

ssize_t writen(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nwrite;
	char *bufp = usrbuf;
	while(nleft > 0)
	{
		if((nwrite = write(fd, bufp, nleft)) <= 0)
		{
			if(errno == EINTR)
			{
				nwrite = 0;
			}
			else
				return -1;
		}
		nleft -= nwrite;
		bufp += nwrite;
	}
	return n;
}

int main(int argc, const char *argv[])
{
	int fd = open("1.txt", O_RDONLY, 0666);
	if(fd == -1)
	{
		ERR_EXIT("open");
	}
	
	char buf[128] = "";
	int ret;
	while((ret = readn(fd, buf, 5)) > 0)
	{
		writen(STDOUT_FILENO, buf, ret);
	}


	return 0;
}
