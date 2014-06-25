/*************************************************************************
	> File Name: hello.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 10:52:57 AM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	printf("hello world\n");
	return 0;
}
