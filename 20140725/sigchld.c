/*************************************************************************
	> File Name: sigchld.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 16时31分27秒
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


#define N 10

void handler(int signum)
{
	pid_t pid;
	while((pid = waitpid(-1, NULL, 0)) > 0)
	{
		printf("handler process child %d\n", pid);
		sleep(2);
	}
}

int main(int argc, const char *argv[])
{
	if(signal(SIGCHLD, handler) == SIG_ERR)
		ERR_EXIT("signal");
	
	pid_t pid;
	int i = 0;
	for(i = 0; i < N; i++)
	{
		if((pid = fork()) < 0)
			ERR_EXIT("fork");
		else if(pid == 0)
		{
			printf("hello from child %d\n", getpid());
			sleep(2);
			exit(EXIT_SUCCESS);
		}
		
	}


	int n;
	char buf[128] = "";
	if((n = read(STDIN_FILENO, buf, 128)) < 0)
		ERR_EXIT("read");
	printf("input\n");
	while(1);
	return 0;
}
