/*************************************************************************
	> File Name: getTime.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 15时08分40秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	time_t t;
	time(&t);
	printf("time = %d\n", (int)t);

	struct tm *pt = gmtime(&t);
	printf("%04d-%02d-%02d %02d-%02d-%02d\n",
			pt->tm_year + 1900,
			pt->tm_mon + 1,
			pt->tm_mday,
			pt->tm_hour + 8,
			pt->tm_min,
			pt->tm_sec);
	return 0;
}
