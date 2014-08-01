/*************************************************************************
	> File Name: getopt.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 16时09分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main(int argc, char *argv[])
{
	
	int opt;
	while(1)
	{
		opt = getopt(argc, argv, "tn:");
		if(opt == '?')
			ERR_EXIT("getopt");
		else if(opt == -1)
			break;
		switch(opt)
		{
			case 't':
				printf("-t\n");
				break;
			case 'n':
				printf("-n : %d\n", atoi(optarg));
				break;
		}
	}
	return 0;
}
