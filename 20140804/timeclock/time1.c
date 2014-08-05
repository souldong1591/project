/*************************************************************************
	> File Name: time1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 19时47分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timerfd.h>
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
	memset(&howlong, 0, sizeof(howlong));
	howlong.it_value.tv_sec = 5;
	howlong.it_interval.tv_sec = 1;
	if(timerfd_settime(timerfd, 0, &howlong, NULL) == -1)
		ERR_EXIT("timerfd_settime");
	
	int ret;
	char buf[1024];
	while((ret = read(timerfd, buf, sizeof(buf))) > 0)
		printf("foobar ...\n");
	close(timerfd);
	return 0;
}
