/*************************************************************************
	> File Name: MutexLock.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 20时20分15秒
 ************************************************************************/

#include "MutexLock.h"
#include <stdexcept>

MutexLock::MutexLock()
{
	if(pthread_mutex_init(&lock_, NULL))
	{
		throw std::runtime_error("init");
	}
}

MutexLock::~MutexLock()
{
	if(pthread_mutex_destroy(&lock_))
	{
		throw std::runtime_error("destroy");
	}
}

void MutexLock::lock()
{
	if(pthread_mutex_lock(&lock_))
	{
		throw std::runtime_error("lock");
	}
}

void MutexLock::unlock()
{
	if(pthread_mutex_unlock(&lock_))
	{
		throw std::runtime_error("unlock");
	}
}
