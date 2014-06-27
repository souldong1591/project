/*************************************************************************
	> File Name: my_popen1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 26 Jun 2014 09:34:25 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[1024] = "";
	int read_n;
	fp = popen("ls -l", "r");
	read_n = fread(buf, 1, 1024, fp);
	printf("read_n = %d\n", read_n);
	printf("read from popen:\n%s\n", buf);
	

	return 0;
}

