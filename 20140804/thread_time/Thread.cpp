/*************************************************************************
	> File Name: Thread.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 20时48分17秒
 ************************************************************************/

#include "Thread.h"

Thread::Thread()
	:tid_(0),
	 isStart_(false)
{}

Thread::Thread(const ThreadFunc &callback)
	:tid_(0),
	 isStart_(false),
	 callback_(callback)
{}

Thread::~Thread()
{
	if(isStart_)
		pthread_detach(tid_);
}

void Thread:: setCallback(const ThreadFunc &callback)
{
	callback_ = callback;
}

void *Thread::threadFunc(void *arg)
{
	Thread *pt = static_cast<Thread *>(arg);
	pt->callback_();
	return NULL;
}

void Thread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void Thread::join()
{
	pthread_join(tid_, NULL);
}
