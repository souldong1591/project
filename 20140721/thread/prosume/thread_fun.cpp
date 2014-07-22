/*************************************************************************
	> File Name: thread_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 19时39分49秒
 ************************************************************************/
#include "thread.h"
#include <iostream>
using namespace std;

void Thread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void *Thread::threadFunc(void *arg)
{
	Thread *pt = static_cast<Thread *>(arg);
	pt->run();
}

void Thread::run()
{
	cout << "run..." << endl;
}

void Thread::join()
{
	pthread_join(tid_, NULL);
}
