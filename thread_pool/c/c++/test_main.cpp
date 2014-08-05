/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月03日 星期日 16时08分41秒
 ************************************************************************/

#include "Thread_pool.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <time.h>
using namespace std;

void *compute(void *arg)
{
	cout << "thread is " << (unsigned int)pthread_self() << ", working on task " << (int)arg << endl;
	sleep(1);
}

int main(int argc, const char *argv[])
{
	Thread_pool pool;
	pool.start();
	for (int i = 0; i < 10; i++)
	{
		Task_t tsk;
		tsk.fp_ = compute;
		tsk.arg_ = (void*)i;
		pool.add_task_to_queue(tsk);
	}
	sleep(5);
	pool.stop();
	return 0;
}
