/*************************************************************************
	> File Name: TimerThread.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月05日 星期二 10时11分00秒
 ************************************************************************/

#include "TimerThread.h"
using namespace std;

void TimerThread::setTimer(int val, int interval)
{
	timer_.setTimer(val, interval);
}

void TimerThread::setTimerCallback(const TimerCallback &callback)
{
	timer_.setTimeCallback(callback);
	thread_.setCallback(bind(&Timer::runTimer, &timer_));
}

void TimerThread::startTimerThread()
{
	thread_.start();
}

void TimerThread::cancelTimerThread()
{
	timer_.cancelTimer();
	thread_.join();
}
