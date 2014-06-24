/*************************************************************************
	> File Name: my_cat.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 10:19:32 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int open_f, read_n;
	char str[1024];

	if(argc == 1)
	{
		while(fflush(stdin),gets(str) != NULL)
		{
			puts(str);
		}
	}
	else if(argc == 2)
	{
		open_f = open(argv[1], O_RDONLY);
		if(open_f == -1)
		{
			perror("fail:");
			exit(-1);
		}
		while(memset(str, 0, 1024), (read_n = read(open_f, str, 1024)) > 0) 
		{
			puts(str);
		}
	}
	else
	{
		printf("more\n");
	}
	close(open_f);

}
