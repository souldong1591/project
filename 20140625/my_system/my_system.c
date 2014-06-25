/*************************************************************************
	> File Name: my_system.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 10:56:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	char buf[128];
	int cnt, iret;
	sprintf(buf, "./hello");
	for(cnt = 1; cnt < argc; cnt++)
	{
		strcat(buf, " ");
		strcat(buf, argv[cnt]);
	}

	iret = system(buf);
	printf("exit status: %d\n", iret);
	return 0;
}


