/*************************************************************************
	> File Name: my_dir.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 11:39:21 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc, char *argv[])
{
	DIR *pDir;
	struct dirent *myent;
	if(argc == 1)
	{
		pDir = opendir(".");
	}
	else
	{
		pDir = opendir(argv[1]);
	}
	if(pDir == NULL)
	{
		perror("open dir:");
		exit(-1);
	}
	while((myent = readdir(pDir)) != NULL)
	{
		printf("size:%d\ttype:%c\tname:%s\n", myent->d_reclen, myent->d_type, myent->d_name);
	}
	return 0;
}

