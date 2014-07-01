/*************************************************************************
	> File Name: pthread_share.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 30 Jun 2014 04:51:04 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int cnt = 0;
pthread_mutex_t mutex;

void* func_sum(void *arg)
{
	int i;
	for(i = 0; i < 10000; i++)
	{
		pthread_mutex_lock(&mutex);
		cnt ++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char *argv[])
{
	pthread_t pthid_1, pthid_2;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&pthid_1, NULL, func_sum, NULL);
	pthread_create(&pthid_2, NULL, func_sum, NULL);
	pthread_join(pthid_1, NULL);
	pthread_join(pthid_2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("cnt = %d\n", cnt);
	
	return 0;
	
}
