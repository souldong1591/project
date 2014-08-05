/*************************************************************************
	> File Name: test_pool.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月03日 星期日 23时19分14秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "ThreadPool.h"
using namespace std;

void func(int i)
{
	cout << i << endl;
}

int main(int argc, const char *argv[])
{
	ThreadPool pool(5, 4);
	pool.start();

	srand(100);
	while(1)
	{
		pool.addTask(bind(&func, rand()%100));
		sleep(1);
	}

	pool.stop();
	return 0;
}
