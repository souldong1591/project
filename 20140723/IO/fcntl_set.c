/*************************************************************************
	> File Name: fcntl_set.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月23日 星期三 17时25分06秒
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

int main(int argc, const char *argv[])
{
	int val = fcntl(STDIN_FILENO, F_GETFL, 0);
	if(val == -1)
	{
		ERR_EXIT("fcntl");
	}

	val |= O_NONBLOCK;
	if(fcntl(STDIN_FILENO, F_SETFL, val) < 0)
	{
		ERR_EXIT("fcntl:set");
	}

	char buf[128] = "";
	int ret = read(STDIN_FILENO, buf, 128);
	if(ret == -1)
	{
		ERR_EXIT("read");
	}
	
	return 0;
}
