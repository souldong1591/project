/*************************************************************************
	> File Name: p_c.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 01 Jul 2014 11:40:15 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
pthread_cond_t c_cond, p_cond;
pthread_mutex_t  mutex;
int empty = 20, full = 0;

void* producer(void *arg);

void* consumer(void *arg);

int main(int argc, char *argv[])
{
	pthread_t pthid_p, pthid_c;
	int pro_num, con_num;
	srand(getpid());
	pthread_mutex_init(&mutex, NULL);

	pthread_cond_init(&p_cond, NULL);
	pthread_cond_init(&c_cond, NULL);
	
	pro_num = atoi(argv[1]);
	con_num = atoi(argv[2]);
	
	while(pro_num > 0 || con_num > 0)
	{
		if(pro_num > 0)
		{
			pthread_create(&pthid_p, NULL, producer, NULL);
		}
		if(con_num > 0)
		{
			pthread_create(&pthid_c, NULL, consumer, NULL);
		}
		pro_num--;
		con_num--;
	}
	while(1);

	pthread_cond_destroy(&c_cond);
	pthread_cond_destroy(&p_cond);

	pthread_mutex_destroy(&mutex);


	return 0;
}

void* producer(void *arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(empty == 0)
		{
			pthread_cond_wait(&p_cond, &mutex);
		}

		printf("a producer in, now num = %d\n", full);
		full++;
		if(full == 1)
		{
			pthread_cond_broadcast(&c_cond);
		}
		printf("a producer out, now num = %d\n", full);
		empty--;
		sleep(rand()%2 + 1);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%2);
	}
	return 0;
}

void *consumer(void *arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(full == 0)
		{
			pthread_cond_wait(&c_cond, &mutex);
		}

		printf("a consumer in, now num = %d\n", full);
		full--;
		if(full == 0)
		{
			pthread_cond_broadcast(&p_cond);
		}
		printf("a consumer out, now num = %d\n", full);
		empty++;
		sleep(rand()%2 + 1);
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
	return 0;

}
