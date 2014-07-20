/*************************************************************************
	> File Name: func.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月19日 星期六 23时20分17秒
 ************************************************************************/

#include "head.h"

void leftShift(char *arr, int len)
{
	size_t tmpLen = strlen(arr);
	char tmpChar;
	int i, j;
	if(n >= 0)
	{
		tmpChar = *arr;
		for(j = 0; j < tmpLen -1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + tmpLen - 1) = tmpChar;
	}
	else
	{
		for(i = 0; i < -n; i++)
		{
			tmpChar = *(arr + tmpLen -1);
			for(j = tmpLen - 1; j > 0; j--)
			{
				*(arr + j) = *(arr + j - 1);
			}
			*arr = tmpChar;
		}
	}
}
