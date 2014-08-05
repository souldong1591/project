/*************************************************************************
	> File Name: thread_pool_func.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 22时48分16秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "thread_pool.h"

//初始化线程池
void thread_pool_init(pool_t *pool, size_t size)
{
	pool->size_ = size;
	pool->threads_ = (pthread_t*)malloc(pool->size_ * sizeof(pthread_t));
	pthread_mutex_init(&pool->mutex_, NULL);
	pthread_cond_init(&pool->cond_, NULL);
	queue_init(&pool->queue_);
	pool->is_start_ = FALSE;
}

//销毁线程池
void thread_pool_destroy(pool_t *pool)
{
	free(pool->threads_);
	thread_pool_stop(pool);
	pthread_mutex_destroy(&pool->mutex_);
	pthread_cond_destroy(&pool->cond_);
	queue_destroy(&pool->queue_);

}


void *thread_pool_func(void *arg)
{
	//从线程池中取任务
	pool_t *pool = (pool_t*)arg;
	task_t task;
	while(1)
	{
		bool flag = thread_pool_get_task_from_queue(pool, &task);
		if(flag == FALSE)
			break;     //获取任务失败，说明线程池已关闭
		else
			task.task_func_(task.arg_);	//执行任务
	}
	return NULL;
}


//开启线程池
void thread_pool_start(pool_t *pool)
{
	if(pool->is_start_ == FALSE)
	{
		pool->is_start_ = TRUE;
		int i;
		for (i = 0; i < pool->size_; i++) 
		{
			pthread_create(&pool->threads_[i], NULL, thread_pool_func, pool);
		}
	}
}


//关闭线程池
void thread_pool_stop(pool_t *pool)
{
	if(pool->is_start_ == FALSE)	//已经关闭，无须再次关闭
		return;

	pool->is_start_ = FALSE;

	//激活所有等待任务的线程
	//确保所有线程被关闭（broadcast）
	pthread_cond_broadcast(&pool->cond_);
	int i;
	for (i = 0; i < pool->size_; i++) 
	{
		pthread_join(pool->threads_[i], NULL);
	}
	queue_clear(&pool->queue_);
}


//线程池是否开启
bool thread_pool_is_start(const pool_t *pool)
{
	return pool->is_start_;
}


//任务队列大小
size_t thread_pool_get_task_queue_size(pool_t *pool)
{
	return queue_getSize(&(pool->queue_));
}


//添加任务
void thread_pool_add_task_to_queue(pool_t *pool, task_t task)
{
	pthread_mutex_lock(&pool->mutex_);
	if(pool->is_start_)
	{
		queue_push(&pool->queue_, task);
		pthread_cond_signal(&pool->cond_);
	}
	pthread_mutex_unlock(&pool->mutex_);
}


//获取任务成功，返回TRUE，任务放在task里面
//否则返回FALSE
bool thread_pool_get_task_from_queue(pool_t *pool, task_t *task)
{
	pthread_mutex_lock(&pool->mutex_);
	while(queue_empty(&pool->queue_) && pool->is_start_ == TRUE)
		//这里被唤醒有两种
		//任务到来，被signal唤醒
		//线程池关闭，被broadcast唤醒
		pthread_cond_wait(&pool->cond_, &pool->mutex_);

	//说明线程池被关闭
	//上面的wait是被broadcast唤醒的
	if(pool->is_start_ == FALSE)
	{
		pthread_mutex_unlock(&pool->mutex_);
		return FALSE;
	}
	*task = queue_front(&pool->queue_);
	queue_pop(&pool->queue_);
	pthread_mutex_unlock(&pool->mutex_);
	return TRUE;
}

