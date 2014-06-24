/*************************************************************************
	> File Name: my_dup2.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 04:07:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int fd;
	fd = open("a.txt", O_WRONLY | O_CREAT, 0666);
	dup2(fd, 1);
	close(fd);

	printf("hello world\n");
	return 0;
}
