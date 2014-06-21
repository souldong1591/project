/*************************************************************************
	> File Name: my_rmdir.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 10:22:01 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int rt;
	rt = rmdir(argv[1]);
	if(rt != 0)
	{
		perror("rmdir:");
	}
	return 0;
}
