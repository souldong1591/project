/*************************************************************************
	> File Name: atexit.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月24日 星期四 21时47分12秒
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

void test1()
{
	printf("test1......\n");
}

void test2()
{
	printf("test2......\n");
}

void test3()
{
	printf("test3......\n");
}

int main(int argc, const char *argv[])
{
	atexit(test1);
	atexit(test2);
	atexit(test3);
	
	_exit(EXIT_SUCCESS);
//	exit(EXIT_SUCCESS);
//	return 0;
}
