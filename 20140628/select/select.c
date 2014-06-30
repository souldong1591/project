/*************************************************************************
	> File Name: select.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 28 Jun 2014 07:00:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
int main(int argc, char *argv[])
{
	 int keyboard;
	 int ret, i;
	 char c;
	 fd_set read_set;
	 struct timeval tm;
	 keyboard = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	 assert(keyboard > 0);
	 while(1)
	 {
		tm.tv_sec = 5;
		tm.tv_usec = 0;
		FD_ZERO(&read_set);
		FD_SET(keyboard, &read_set);
		ret = select(keyboard + 1, &read_set, NULL, NULL, &tm);
		if(ret == -1)
		{
			perror("select error");
			
		}
		else if(ret)
		{
			if(FD_ISSET(keyboard, &read_set))
			{
				i = read(keyboard, &c, 1);
				if(c == '\n')
				{
					continue;
				}
				printf("input is %c\n", c);
				if(c == 'q')
				{
					break;
				}
			}
		
		}
		else if(ret == 0)
		{
			printf("time out\n");
		}
	 }

}
