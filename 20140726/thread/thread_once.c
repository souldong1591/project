/*************************************************************************
	> File Name: thread_once.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月26日 星期六 17时00分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

pthread_once_t once_control = PTHREAD_ONCE_INIT;

void test()
{
	printf("test......\n");
}

void *threadFunc(void *arg)
{
	pthread_once(&once_control, test);
	printf("in thread...\n");
	return NULL;
}

int main(int argc, const char *argv[])
{
	pthread_t threads[10];
	int i = 0;
	for (i = 0; i < 10; i++) 
	{
		pthread_create(&threads[i], NULL, threadFunc, NULL);
	}

	for (i = 0; i < 10; i++) 
	{
		pthread_join(threads[i], NULL);
	}
	return 0;
}
