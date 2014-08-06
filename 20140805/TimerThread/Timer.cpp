/*************************************************************************
	> File Name: Timer.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 20时27分39秒
 ************************************************************************/

#include "Timer.h"
#include <poll.h>
#include <unistd.h>
#include <string.h>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

Timer::Timer()
	:isStarted_(false)
{
	timerfd_ = ::timerfd_create(CLOCK_REALTIME, 0);
	if(timerfd_ == -1)
		ERR_EXIT("timerfd_create");
	bzero(&howlong_, sizeof(howlong_));

}

Timer::~Timer()
{
	::close(timerfd_);
}

void Timer::setTimer(int val, int interval)
{
	howlong_.it_value.tv_sec = val;
	howlong_.it_interval.tv_sec = interval;
}

void Timer::setTimeCallback(const TimeCallback & timeCallback)
{
	timeCallback_ = timeCallback;
}

void Timer::runTimer()
{
	struct pollfd event[1];
	event[0].fd = timerfd_;
	event[0].events = POLLIN;
	char buf[1024] = "";
	int nready;
	if(timerfd_settime(timerfd_, 0, &howlong_, NULL) == -1)
		ERR_EXIT("timerfd_settime");

	isStarted_ = true;
	while(isStarted_)
	{
		nready = poll(event, 1, 10000);
		if(nready == -1)
			ERR_EXIT("poll");
		else if(nready == 0)
			printf("timeout\n");
		else
		{
			if(read(timerfd_, buf, sizeof(buf)) == -1)
				ERR_EXIT("read");
			timeCallback_();
		}
	}
}

void Timer::cancelTimer()
{
	bzero(&howlong_, sizeof(howlong_));
	if(timerfd_settime(timerfd_, 0, &howlong_, NULL) == -1)
		ERR_EXIT("timerfd_settime");
	isStarted_ = false;
}
