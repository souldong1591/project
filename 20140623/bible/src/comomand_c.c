/*************************************************************************
	> File Name: comomand_c.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 24 Jun 2014 09:00:23 AM CST
 ************************************************************************/

#include "bible.h"

void command_c(char *str, char *left, char *right)
{
	int i = 0, j = 0;
	for(i = 0; i < 6; i++)
	{
		left[i] = str[i];
	}
	
	while(str[i] != '\0')
	{
		right[j] = str[i];
		i++;
		j++;
	}


}
