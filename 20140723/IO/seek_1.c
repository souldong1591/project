/*************************************************************************
	> File Name: seek_1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月23日 星期三 15时50分14秒
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

	off_t len = lseek(fd, 0, SEEK_END);
	printf("size = %d\n", (int)len);
	close(fd);
	return 0;
}
