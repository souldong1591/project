/*************************************************************************
	> File Name: hello_fork.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月24日 星期四 21时08分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, const char *argv[])
{

	printf("hello 0\n");
	fork();
	printf("hello 1\n");
	fork();
	printf("hello 2\n");
	fork();
	printf("hello 3\n");
	return 0;
}
