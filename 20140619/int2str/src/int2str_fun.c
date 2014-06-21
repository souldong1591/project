/*************************************************************************
	> File Name: int2str_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 10:27:22 AM CST
 ************************************************************************/

#include"int2str.h"
void int2str(int a, char *s)
{
	int n = 10, count = 1, i;
	while(a/n != 0)
	{
		count++;
		n = n*10;
	}
	n = n/10;
	for(i = 0; i < count - 1; i++)
	{
		s[i] = (a/n) + '0';
		x = x*10 + a/n;
		n = n/10;
	}
	s[count] = (a%10) + '0';
}
