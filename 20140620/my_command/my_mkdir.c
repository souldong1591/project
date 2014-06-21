/*************************************************************************
	> File Name: my_mkdir.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 10:16:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int rt;
	rt = mkdir(argv[1], 0777);
	if(rt != 0)
	{
		perror("mkdir:");
	}
	return 0;
}
