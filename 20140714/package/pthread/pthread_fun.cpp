/*************************************************************************
	> File Name: pthread_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 20时00分28秒
 ************************************************************************/

#include "thread.h"
#include <time.h>
#include <unistd.h>
#include <iostream>
using namespace std;

Thread::Thread()
	:tid_(-1), a_(0)
{}

Thread::~Thread()
{}

void Thread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void *Thread::threadFunc(void *arg)
{
	Thread *pt = static_cast<Thread*>(arg);
	pt->run();
}

void Thread::run()
{
	while(1)
	{
		cout << ++a_ << endl;
		sleep(1);
	}
}

void Thread::join()
{
	pthread_join(tid_, NULL);
}


