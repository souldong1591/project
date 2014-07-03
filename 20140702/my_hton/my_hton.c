/*************************************************************************
	> File Name: my_hton.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 02 Jul 2014 09:41:55 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define myhton(ip) \
	(ip & (unsigned)0xff) << 24 | \
	(ip & (unsigned)(0xff) << 8) << 8 | \
	(ip & (unsigned)(0xff) << 16) >> 8 | \
	(ip & (unsigned)(0xff) << 24) >> 24

int main(int argc, char *argv[])
{
	int ip_h, ip_n;
	int buf[4] ;
	char str[50] = "";
	char ip[50] = "";
	printf("Please enter ip:");
	scanf("%s", str);
	sscanf(str, "%d.%d.%d.%d", &buf[0], &buf[1], &buf[2], &buf[3]);
	ip_h = (buf[0]) | (buf[1] << 8) | (buf[2] << 16) |(buf[3] << 24);
	ip_n = myhton(ip_h);
	printf("h:%x\n", ip_h);
	printf("n:%x\n", ip_n);
	memset(buf, 0, 4);
	buf[0] = (ip_n & ((unsigned)0xff << 24)) >> 24;
	buf[1] = (ip_n & ((unsigned)0xff << 16)) >> 16;
	buf[2] = (ip_n & ((unsigned)0xff << 8)) >> 8;
	buf[3] = (ip_n & ((unsigned)0xff));
	sprintf(ip, "%d.%d.%d.%d", buf[0], buf[1], buf[2], buf[3]);
	puts(ip);

	return 0;
}
