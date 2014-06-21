/*************************************************************************
	> File Name: doub2str.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 08:03:13 PM CST
 ************************************************************************/

#include"doub2str.h"
void doub2str(double num, char *str)
{
	int front, last;
	int abs, n = 0;
	int bg, end;
	front = (int)num;
	abs = front >0 ? front : -front;
	last = (int)((num - front)*100);
	while(abs)
	{
		str[n] = abs%10 +'0';
		abs = abs/10;
		n++;
	}
	if(front < 0)
	{
		str[n] = '-';
	}
	bg = 0;
	end = n -1;
	while(bg < end)
	{
		str[bg] = str[end];
		bg++;
		end--;
	}
	str[n] = '.';
	str[n+1] = last/10 + '0';
	str[n+2] = last%10 + '0';
	str[n+3] = '\0';

}
