/*************************************************************************
	> File Name: time2.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 20时03分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timerfd.h>
#include <poll.h>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

int main(int argc, const char *argv[])
{
	int timerfd = timerfd_create(CLOCK_REALTIME, 0);
	if(timerfd == -1)
		ERR_EXIT("timerfd_create");

	struct itimerspec howlong;
	bzero(&howlong, sizeof(howlong));
	howlong.it_value.tv_sec = 5;
	howlong.it_interval.tv_sec = 1;
	if(timerfd_settime(timerfd, 0, &howlong, NULL) == -1)
		ERR_EXIT("timerfd_settime");

	struct pollfd event[1];
	event[0].fd = timerfd;
	event[0].events = POLLIN;
	char buf[1024] = "";
	while(1)
	{
		int ret = poll(event, 1, 10000);
		if(ret == -1)
			ERR_EXIT("poll");
		else if(ret == 0)
			printf("timeout\n");
		else
		{
			if(read(timerfd, buf, sizeof(buf)) == -1)
				ERR_EXIT("read");
			printf("foobar ...\n");
		}
	}
	
	close(timerfd);
	return 0;
}
