/*************************************************************************
	> File Name: pthread_1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 30 Jun 2014 11:33:12 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *ThreadFunc(void *pArg)
{
	int i = 0;
//	for(; i < 10; i++)
	{
		printf("Hi, I'm child thread, arg is: %d\n", (int)pArg);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main(int aegc, char *argv[])
{
	pthread_t thdId;
	pthread_create(&thdId, NULL, ThreadFunc, (void*)123);
	sleep(5);
	int i = 0;
//	for(; i < 10; i++)
	{
		printf("Hi, I'm main thread id is: %x\n", thdId);
		sleep(1);
	}
	return 0;
}
