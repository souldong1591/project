/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 22时27分57秒
 ************************************************************************/

#include "Rio.h"
#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;
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
		ERR_EXIT("open");
	
	Rio rio(fd);
	int ret;
	char buf[128] = "";
	while((ret = rio.rio_readline(buf, 128)) > 0)
		rio.rio_writen(STDOUT_FILENO, buf, strlen(buf));
	return 0;
}
