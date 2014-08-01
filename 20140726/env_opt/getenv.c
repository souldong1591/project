/*************************************************************************
	> File Name: getenv.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 16时06分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	printf("SHELL = %s\n", getenv("SHELL"));
	return 0;
}
