/*************************************************************************
	> File Name: my_cd.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 10:02:10 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	int rt;
	rt = chdir(argv[1]);
	if(rt != 0)
	{
		perror("cd:");
	}
	else
	{
		system("pwd");	
		getchar();
	}
	return 0;
}
