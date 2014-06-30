/*************************************************************************
	> File Name: text1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 28 Jun 2014 04:02:01 PM CST
 ************************************************************************/

#include <stdio.h>

int main()
{
	printf("core dump\n");
	*(char *)0 = 0;
	return 0;
}
