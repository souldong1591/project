/*************************************************************************
	> File Name: test_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 23时40分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "thread_pool.h"

void *compute(void *arg)
{
	
	printf("thread is %x, working on task %d\n", (unsigned int)pthread_self(), (int)arg);
	sleep(1);
	return NULL;
}


int main(int argc, const char *argv[])
{

	pool_t pool;
	thread_pool_init(&pool, THREAD_POOL_SIZE);
	thread_pool_start(&pool);
	int i;
	for (i = 0; i < 10; i++) 
	{
		task_t tsk;
		tsk.task_func_ = compute;
		tsk.arg_ = (void*)i;
		thread_pool_add_task_to_queue(&pool, tsk);
	}
	
	sleep(5);
	thread_pool_stop(&pool);
	thread_pool_destroy(&pool);
	return 0;	
}
