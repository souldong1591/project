/*************************************************************************
	> File Name: ctime.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 15时13分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	time_t t;
	time(&t);
	printf("time: %s\n", ctime(&t));
	return 0;
}
