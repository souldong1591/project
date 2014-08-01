/*************************************************************************
	> File Name: wait.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 10时10分01秒
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

int main(int argc, const char *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid == -1)
		ERR_EXIT("fork");
	else if(pid > 0)
	{
		int ret = wait(NULL);
		printf("child = %d\n", ret);
		sleep(5);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
	return 0;
}
