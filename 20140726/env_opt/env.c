/*************************************************************************
	> File Name: env.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 16时01分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int argc, const char *argv[])
{
	int i;
	for (i = 0; environ[i] != NULL; i++) 
	{
		printf("%d: %s\n", i, environ[i]);
	}
	return 0;
}
