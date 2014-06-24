/*************************************************************************
	> File Name: d_space.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 10:39:48 PM CST
 ************************************************************************/

#include "bible.h"
void d_space(char *str)
{
	char *t;
	int i = 0, j =0;
	t = str;
	while(t[i] != '\0')
	{
		if(t[i] != ' ')
		{
			str[j] = t[i];
			j++;
			i++;
		}
		else
		{
			i++;
		}
	}
	str[j] = '\0';
}
