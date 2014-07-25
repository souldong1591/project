/*************************************************************************
	> File Name: fcntl.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月23日 星期三 16时44分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
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
	int fd = open("1.txt", O_RDONLY, 0666);
	if(fd == -1)
	{
		ERR_EXIT("open");
	}
	
	int fd2 = fcntl(fd, F_DUPFD, 0);
	if(fd2 == -1)
	{
		ERR_EXIT("fcntl");
	}

	char buf[128] = "";
	read(fd2, buf, 128);
	fputs(buf, stdout);
	close(fd);
	close(fd2);


	return 0;
}
