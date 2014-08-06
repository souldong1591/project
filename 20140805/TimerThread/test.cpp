/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 21时29分20秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include "TimerThread.h"

using namespace std;

void foobar()
{
	cout << "hello world" << endl;
}

int main(int argc, const char *argv[])
{
	TimerThread foo;
	foo.setTimer(3, 1);
	foo.setTimerCallback(&foobar);

	foo.startTimerThread();
	sleep(10);
	foo.cancelTimerThread();
	return 0;
}
