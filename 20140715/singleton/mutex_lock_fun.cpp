/*************************************************************************
  > File Name: mutex_lock_fun.cpp
  > Author: Soul
  > Mail:souldong1591@gmail.com 
  > Created Time: 2014年07月15日 星期二 14时43分23秒
 ************************************************************************/

#include "mutex_lock.h"
#include <stdexcept>

Mutex_lock::Mutex_lock()
{
	if(pthread_mutex_init(&lock_, NULL))
	{
		throw std::runtime_error("init failed");
	}
}

Mutex_lock::~Mutex_lock()
{
	if(pthread_mutex_destroy(&lock_))
	{
		throw std::runtime_error("destroy failed");
	}
}

void Mutex_lock::lock()
{
	if(pthread_mutex_lock(&lock_))
	{
		throw std::runtime_error("lock failed");
	}
}

void Mutex_lock::unlock()
{
	if(pthread_mutex_unlock(&lock_))
	{
		throw std::runtime_error("unlock failed");
	}
}

pthread_mutex_t *Mutex_lock::getMutexLockPtr()
{
	return &lock_;
}
