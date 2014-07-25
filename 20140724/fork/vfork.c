/*************************************************************************
	> File Name: vfork.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月24日 星期四 21时34分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int g_val = 10;

int main(int argc, const char *argv[])
{
	pid_t pid = vfork();
	if(pid == -1)
		ERR_EXIT("fork");
	else if(pid > 0)
	{
		sleep(2);
		printf("g_val = %d\n", g_val);
		sleep(3);
	}
	else
	{
		++g_val;
		printf("g_val = %d\n", g_val);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
