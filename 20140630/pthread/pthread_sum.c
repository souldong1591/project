/*************************************************************************
	> File Name: pthread_sum.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 30 Jun 2014 02:51:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#define M 10000

void* sum(void *arg)
{
	int *a;
	char *p = "hello world";
	int i = 0;
	double sum = 0;
	a = (int *)arg;
	for(i = 0; i < M; i++)
	{
		sum += a[i];
	}
	printf("sum = %lf\n", sum);
	return (void *)p;
	
}

int main(int argc, char *argv[])
{
	pthread_t pthid;
	int *a;
	int p_iret;
	char *p_cret;
	int i = 0;
	a = (int *)calloc(M, sizeof(int));
	srand(time(NULL));
	for(i = 0;i < M; i++)
	{
		a[i] = rand()%100;
	}
	pthread_create(&pthid, NULL, sum, (void *)a);
	pthread_join(pthid, (void *)&p_cret);
	printf("ret = %s\n",p_cret);
	sleep(1);
	return 0;
}
