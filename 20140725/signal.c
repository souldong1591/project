/*************************************************************************
	> File Name: signal.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 15时26分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

void handler(int signum)
{
	printf("Ctrl C, signum = %d\n", signum);
}

int main(int argc, const char *argv[])
{
	if(signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal");
	
	int n = 5;
	do
	{
		n = sleep(n);
	}while(n > 0);
	return 0;
}
