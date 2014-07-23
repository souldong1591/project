/*************************************************************************
	> File Name: thread_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 10时30分24秒
 ************************************************************************/

#include "thread.h"

void Thread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void *Thread::threadFunc(void *arg)
{
	Thread *pt = static_cast<Thread *>(arg);
	pt->run();
}

void Thread::join()
{
	pthread_join(tid_, NULL);
}

