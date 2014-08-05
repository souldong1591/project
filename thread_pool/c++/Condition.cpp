/*************************************************************************
	> File Name: Condition.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月03日 星期日 20时58分06秒
 ************************************************************************/

#include "Condition.h"
#include "MutexLock.h"

Condition::Condition(MutexLock &mutex)
	:mutex_(mutex)
{
	pthread_cond_init(&cond_, NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&cond_);
}

void Condition::wait()
{
	assert(mutex_.isLocked());
	pthread_cond_wait(&cond_, mutex_.getMutexPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&cond_);
}

void Condition::notifyAll()
{
	pthread_cond_broadcast(&cond_);
}
