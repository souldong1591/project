/*************************************************************************
	> File Name: open_1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月23日 星期三 15时36分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main(int argc, const char *argv[])
{
	int fd1 = open("1.txt", O_RDONLY, 0666);
	if(fd1 == -1)
	{
		ERR_EXIT("open");
	}
	
	int fd2 = open("2.txt", O_RDONLY, 0666);
	if(fd2 == -1)
	{
		ERR_EXIT("open");
	}

	char buf1[1024] = "";
	read(fd1, buf1, 5);
	printf("buf1 = %s\n", buf1);

	char buf2[1024] = "";
	read(fd2, buf2, 5);
	printf("buf2 = %s\n", buf2);


	read(fd1, buf1, 5);
	printf("buf1 = %s\n", buf1);

	read(fd2, buf2, 5);
	printf("buf2 = %s\n", buf2);

	close(fd1);
	close(fd2);
	return 0;
}
