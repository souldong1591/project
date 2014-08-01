/*************************************************************************
	> File Name: my_system.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 20时43分42秒
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

int my_system(const char *command)
{
	if(command == NULL)
		return 1;
	int status;
	pid_t pid;
	if((pid = fork()) < 0)
		ERR_EXIT("open");
	else if(pid == 0)
	{
		execl("/bin/sh", "sh", "-c", command, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		while(waitpid(pid, &status, 0) < 0)
		{
			if(errno == EINTR)
				continue;
			status = -1;
			break;
		}
	}
	return status;
}

int main(int argc, const char *argv[])
{
	printf("in main....\n");
	my_system("ls");
	printf("out main....\n");
	return 0;
}
