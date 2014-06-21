/*************************************************************************
	> File Name: my_strstr.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 11:17:26 AM CST
 ************************************************************************/

#include"my_strstr.h"
char *strstr_fun(char *str1, char *str2)
{
	int i, j, flag = 0;
	for(i = 0; str1[i] != '\0'; i++)
	{
		flag = 0;
		for(j = 0; str2[j] != '\0'; j++)
		{
			if(str1[i + j] != str2[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			return &str1[i];
		}
	}
}
