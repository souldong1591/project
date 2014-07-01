/*************************************************************************
	> File Name: read_write.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 30 Jun 2014 05:21:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>

int r_count = 0, n = 3;
pthread_mutex_t mutex, r_mutex, w_mutex;


void* read_n(void *arg);
void* write_n(void *arg);

int main(int argc, char *argv[])
{
	pthread_t pthid_r, pthid_w;
	int num;
	srand(getpid());
		pthread_mutex_init(&mutex, NULL);
		pthread_mutex_init(&r_mutex, NULL);
		pthread_mutex_init(&w_mutex, NULL);
	while(1)
	{
		num = rand();
		if(num%2 == 0)
		{
			pthread_create(&pthid_r, NULL, read_n, NULL);
		}
		else
		{
			pthread_create(&pthid_w, NULL, write_n, NULL);
		}
		sleep(1);

	}
		pthread_mutex_destroy(&mutex);
		pthread_mutex_destroy(&r_mutex);
		pthread_mutex_destroy(&w_mutex);
	return 0;
}

void* read_n(void *arg)
{
	pthread_detach(pthread_self());

	pthread_mutex_lock(&r_mutex);
	if(r_count == 0)
	{
		pthread_mutex_lock(&mutex);
	}
	r_count++;
	pthread_mutex_unlock(&r_mutex);
	
	printf("read n = %d\n", n);
	sleep(1);

	pthread_mutex_lock(&r_mutex);
	r_count--;
	if(r_count == 0)
	{
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&r_mutex);
	return 0;
	
}

void* write_n(void *arg)
{
	pthread_detach(pthread_self());

	pthread_mutex_lock(&w_mutex);
	pthread_mutex_lock(&mutex);
	printf("write before n = %d\n", n);
	sleep(1);
	n++;
	printf("write after n = %d\n", n);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&w_mutex);
	return 0;
}
