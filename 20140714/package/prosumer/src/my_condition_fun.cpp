/*************************************************************************
	> File Name: my_condition_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 14时56分02秒
 ************************************************************************/

#include "my_condition.h"
#include "mutex_lock.h"
#include <stdexcept>

using namespace std;

Condition::Condition(Mutex_lock &lock)
		:lock_(lock)
{
	if(pthread_cond_init(&con_, NULL))
	{
		throw std::runtime_error("init failed");
	}
}

Condition::~Condition()
{
	if(pthread_cond_destroy(&con_))
	{
		throw std::runtime_error("destroy failed");
	}
}

void Condition::wait()
{
	if(pthread_cond_wait(&con_, lock_.getMutexLockPtr()))
	{
		throw std::runtime_error("wait failed");
	}
}

void Condition::notify()
{
	if(pthread_cond_signal(&con_))
	{
		throw std::runtime_error("signal failed");	
	}

}

void Condition::notifyAll()
{
	if(pthread_cond_broadcast(&con_))
	{
		throw std::runtime_error("broadcast failed");
	}
}

