/*************************************************************************
	> File Name: seek_2.c
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
	int fd = open("3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(fd == -1)
	{
		ERR_EXIT("open");
	}

	char buf[128] = "hello";
	write(fd, buf, strlen(buf));
	off_t len = lseek(fd, 1024*1024*1024, SEEK_CUR);
	write(fd, "world", strlen("world"));
	printf("size = %d\n", (int)len);
	close(fd);
	return 0;
}
