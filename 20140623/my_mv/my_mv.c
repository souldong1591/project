/*************************************************************************
	> File Name: my_mv.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 02:05:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int fd_r, fd_w, read_n, write_n;
	char buf[1024];
	if(argc != 3)
	{
		printf("error!\n");
		exit(-1);
	}

	if(strcmp(argv[1], argv[2]) == 0)
	{
		rename(argv[1], argv[2]);
		return 0;
	}
	fd_r = open(argv[1], O_RDONLY);
	fd_w = open(argv[2], O_WRONLY | O_CREAT, 0666);
	if((fd_r == -1) || (fd_w == -1))
	{
		perror("fail:");
		exit(-1);
	}
	while(memset(buf, 0, 1024), (read_n = read(fd_r, buf, 1024)) > 0)
	{
		write_n = write(fd_w, buf, read_n);
		if(write_n == -1)
		{
			perror("fail:");
			exit(-1);
		}
	}

	close(fd_r);
	close(fd_w);

	unlink(argv[1]);
	return 0;
}
