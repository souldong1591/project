/*************************************************************************
	> File Name: my_execl.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 03:09:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	printf("execl begin...\n");
	execl("../my_system/hello", "hello", "world", NULL);
	printf("execl end!\n");

	return 0;
}
