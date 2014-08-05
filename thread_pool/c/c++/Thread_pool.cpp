/*************************************************************************
	> File Name: Thread_pool.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月01日 星期五 22时40分15秒
 ************************************************************************/

#include "Thread_pool.h"

Thread_pool::Thread_pool()
	:size_(THREAD_POOL_SIZE),
	 is_start_(false)
{
	threads_ = (pthread_t *)malloc(size_ * sizeof(pthread_t)); 
	pthread_mutex_init(&mutex_, NULL);
	pthread_cond_init(&cond_, NULL);
}

Thread_pool::~Thread_pool()
{
	free(threads_);
	stop();
	pthread_mutex_destroy(&mutex_);
	pthread_cond_destroy(&cond_);

}

void *Thread_pool::thread_pool_func(void *arg)
{
	Thread_pool *pt = static_cast<Thread_pool *>(arg);
	Task_t task;
	while(1)
	{
		bool flag = pt->get_task_from_queue(&task);
		if(flag == false)
			break;
		else
			task.fp_(task.arg_);
	}
	return NULL;
}

void Thread_pool::start()
{
	if(is_start_ == false )
	{
		is_start_ = true;
		for (int i = 0; i < size_; i++)
		{
			pthread_create(&threads_[i], NULL, thread_pool_func, this);
		}
	}
}

void Thread_pool::stop()
{
	if(is_start_ == false)
		return;
	is_start_ = true;

	pthread_cond_broadcast(&cond_);
	for (int i = 0; i < size_; i++)
	{
		pthread_join(threads_[i], NULL);
	}
	queue_.clear();
}
bool Thread_pool::is_start()
{
	return is_start_;
}

size_t Thread_pool::get_task_queue_size()
{
	return queue_.size();
}

void Thread_pool::add_task_to_queue(Task_t tsk)
{
	pthread_mutex_lock(&mutex_);
	if(is_start_)
	{
		queue_.push(tsk);
		pthread_cond_signal(&cond_);
	}
	pthread_mutex_unlock(&mutex_);
}

bool Thread_pool::get_task_from_queue(Task_t *tsk)
{
	pthread_mutex_lock(&mutex_);
	while(queue_.empty() && is_start_ == true)
		pthread_cond_wait(&cond_, &mutex_);
	if(is_start_ == false)
	{
		pthread_mutex_unlock(&mutex_);
		return false;
	}
	*tsk = queue_.front();
	queue_.pop();
	pthread_mutex_unlock(&mutex_);
	return true;
}

