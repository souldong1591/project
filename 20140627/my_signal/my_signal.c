/*************************************************************************
	> File Name: my_signal.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 27 Jun 2014 09:50:28 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int num)
{
	printf("signal: %d\n", num);
}

int main()
{
	signal(2, my_handler);
	signal(3, my_handler);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
	return 0;
	
}
