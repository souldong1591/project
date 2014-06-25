/*************************************************************************
	> File Name: my_execlvp.c
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
	//char *arglist[] = {"../my_system/hello", "hello", "world", NULL};
	char **arglist;
	int i;
	arglist = (char **)malloc((argc + 1) * sizeof(char *));
	arglist[0] = "../my_system/hello";
	for(i = 1; i <= argc; i++)
	{
		arglist[i] = argv[i];
	}
	arglist[i] = NULL;
	printf("execl begin...\n");
	//execl("../my_system/hello", "hello", "world", NULL);
	execvp(arglist[0], arglist);
	printf("execl end!\n");
	 
	return 0;
}
