/*************************************************************************
	> File Name: produce_thread_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 15时08分58秒
 ************************************************************************/

#include "produce_thread.h"
#include "buffer.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

ProduceThread::ProduceThread(Buffer &buffer)
	:tid_(0), buffer_(buffer)
{
	::srand(time(NULL));
}

void ProduceThread::start()
{
	pthread_create(&tid_, NULL, threadFunc, this);
}

void *ProduceThread::threadFunc(void *arg)
{
	ProduceThread *pt = static_cast<ProduceThread*>(arg);
	pt->run();
	return NULL;
}

void ProduceThread::run()
{
	while(1)
	{
		int data = rand()%100;
		buffer_.produce(data);
		sleep(1);
	}
}

void ProduceThread::join()
{
	pthread_join(tid_, NULL);
}
