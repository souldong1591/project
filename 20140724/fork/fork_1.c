/*************************************************************************
	> File Name: fork_1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月24日 星期四 21时14分56秒
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

int main(int argc, const char *argv[])
{
	//int fd = open("1.txt", O_RDONLY, 0666);
	pid_t pid;
	pid = fork();
	int fd = open("2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1)
		ERR_EXIT("open");
	if(pid == -1)
		ERR_EXIT("fork");
	else if(pid > 0)
	{
		sleep(2);
		/*char buf[128] = "";
		read(fd, buf, 5);
		write(STDOUT_FILENO, buf, strlen(buf));
		sleep(3);*/
		write(fd, "hello", strlen("hello"));
		close(fd);
	}
	else
	{
		/*
		char buf[128] = "";
		read(fd, buf, 5);
		write(STDOUT_FILENO, buf, strlen(buf));
		*/
		write(fd, "world", strlen("world"));
		close(fd);
	}
	return 0;
}
