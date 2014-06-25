/*************************************************************************
	> File Name: my_cat.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 11:19:13 AM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int cnt;
	char buf[128];
	sprintf(buf, "cat");
	for(cnt = 1; cnt < argc; cnt++)
	{
		strcat(buf, " ");
		strcat(buf, argv[cnt]);
	}
	system(buf);
	return 0;
}
