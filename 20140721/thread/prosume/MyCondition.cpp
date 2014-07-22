/*************************************************************************
	> File Name: MyCondition.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 20时32分09秒
 ************************************************************************/

#include "MyCondition.h"
#include "MutexLock.h"
#include <stdexcept>

Condition::Condition(MutexLock &lock):
	lock_(lock)
{
	if(pthread_cond_init(&con_, NULL))
	{
		throw std::runtime_error("init");
	}
}

Condition::~Condition()
{
	if(pthread_cond_destroy(&con_))
	{
		throw std::runtime_error("destroy");
	}
}

void Condition::wait()
{
	if(pthread_cond_wait(&con_, lock_.getMutexLockPtr()))
	{
		throw std::runtime_error("wait");
	}
}

void Condition::notify()
{
	if(pthread_cond_signal(&con_))
	{
		throw std::runtime_error("signal");
	}
}

void Condition::notifyAll()
{
	if(pthread_cond_broadcast(&con_))
	{
		throw std::runtime_error("broadcast");
	}
}

