/*************************************************************************
	> File Name: cl_1.c
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
	int fd_w1, fd_w2, fd_r1, fd_r2, read_n1, read_n2;
	fd_r1 = open("2_1.fifo", O_RDONLY);
	fd_r2 = open("3_1.fifo", O_RDONLY);
	fd_w1 = open("1_2.fifo", O_WRONLY);
	fd_w2 = open("1_3.fifo", O_WRONLY);
	char buf[1024] = "";
	char buf2[1024] = "";

	if(fork() > 0)
	{
		close(fd_r1);
		close(fd_r2);
		FILE *fp1 = fdopen(fd_w1, "w");
		FILE *fp2 = fdopen(fd_w2, "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			fprintf(fp1, "From cl_1:%s", buf);
			fprintf(fp2, "From cl_1:%s", buf);
			fflush(fp1);
			fflush(fp2);
		}
		close(fd_w1);
		close(fd_w2);
		wait(NULL);
	
	}
	else
	{
		close(fd_w1);
		close(fd_w2);
		if(fork() > 0)
		{
			while(memset(buf, 0, 1024),  read(fd_r1, buf, 1024) > 0 )
			{
				write(1, buf, sizeof(buf));
			}
			close(fd_r1);
		}
		else
		{
			
			while(memset(buf, 0, 1024), read(fd_r2, buf, 1024) > 0 )
			{
				write(1, buf, sizeof(buf));
			}
			close(fd_r2);
		}
		
	}
	return 0;
}
