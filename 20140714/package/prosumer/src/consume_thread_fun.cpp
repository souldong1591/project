/*************************************************************************
	> File Name: consume_thread_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 15时20分53秒
 ************************************************************************/

#include "consume_thread.h"
#include "buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

ConsumeThread::ConsumeThread(Buffer &buffer)
	:tid_(0), buffer_(buffer)
{}

void ConsumeThread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void *ConsumeThread::threadFunc(void *arg)
{
	ConsumeThread *pt = static_cast<ConsumeThread *>(arg);
	pt->run();
	return NULL;
}

void ConsumeThread::run()
{
	while(1)
	{
		buffer_.consume();
		sleep(1);
	}
}

void ConsumeThread::join()
{
	pthread_join(tid_, NULL);
}
