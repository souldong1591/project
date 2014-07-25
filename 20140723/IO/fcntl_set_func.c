/*************************************************************************
	> File Name: fcntl_set_func.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月23日 星期三 20时14分59秒
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

void setNonBlock(int fd);
void setBlock(int fd);

int main(int argc, const char *argv[])
{
	setNonBlock(STDIN_FILENO);
	setBlock(STDIN_FILENO);
	char buf[128] = "";
	int ret = read(STDIN_FILENO, buf, 128);
	if(ret == -1)
	{
		ERR_EXIT("read");
	}
	
	return 0;
}

void setNonBlock(int fd)
{
	int val = fcntl(fd, F_GETFL, 0);
	if(val == -1)
	{
		ERR_EXIT("fcntl");
	}
	val |= O_NONBLOCK;
	if(fcntl(fd, F_SETFL, val) < 0)
	{
		ERR_EXIT("fcntl_set");
	}
}

void setBlock(int fd)
{
	int val = fcntl(fd, F_GETFL, 0);
	if(val == -1)
	{
		ERR_EXIT("fcntl");
	}
	val &= ~O_NONBLOCK;
	if(fcntl(fd, F_SETFL, val) < 0)
	{
		ERR_EXIT("fcntl_set");
	}
}
