/*************************************************************************
	> File Name: my_fork.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 05:04:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	int iret, iret_wait;
	printf("hello\n");
	iret = fork();
	if(iret == 0)
	{
		printf("i am c\n");
		printf("pid: %u  ppid: %u \n", getpid(), getppid());
		sleep(10);
		printf("c exit\n");
	}
	else
	{
		printf("i am p\n");
		printf("pid: %u  ppid: %u \n", getpid(), getppid());
		printf("wait...\n");
		iret_wait = (long int)wait(NULL);
		printf("pid: %u\n", iret_wait);
		printf("p exit\n");
	}

	return 0;
}
