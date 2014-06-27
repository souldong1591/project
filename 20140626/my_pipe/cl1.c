/*************************************************************************
	> File Name: cl1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 26 Jun 2014 05:35:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd_w, fd_r;
	fd_r = open("2-1.fifo", O_RDONLY);
	fd_w = open("1-2.fifo", O_WRONLY);
	char buf[1024] = "";

	if(fork() > 0)
	{
		close(fd_r);
		FILE *fp = fdopen(fd_w, "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			fprintf(fp, "From cl1:%s", buf);
			fflush(fp);
		}
		close(fd_w);
		wait(NULL);
	
	}
	else
	{
		close(fd_w);
		while(memset(buf, 0, 1024), read(fd_r, buf, 1024) > 0)
		{
			write(1, buf, sizeof(buf));
		}
		close(fd_r);
		exit(0);
	}
	return 0;
}
