/*************************************************************************
	> File Name: select_sort.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 01:47:46 PM CST
 ************************************************************************/

#include"sort.h"
void select_sort(int *a, int len)
{
	int i,j,k,tmp;
	for(i = 0; i < len; i++)
	{
		k = i;
		for(j = i + 1; j < len; j++)
		{
			if(a[j] < a[k])
			{
				k = j;
			}
		}
		tmp = a[i];
		a[i] = a[k];
		a[k] = tmp;
	}
}
