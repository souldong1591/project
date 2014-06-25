/*************************************************************************
	> File Name: my_id.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 10:18:41 AM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
while(1)
	{
		printf("pid:%d\nppid:%d\nuid:%d\ngid:%d\neuid:%d\nguid:%d\n", 
				getpid(), getppid(), getuid(), getgid(), geteuid(), getegid());
	}

	return 0;
}
