/*************************************************************************
	> File Name: insert_sort.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 12:59:30 PM CST
 ************************************************************************/

#include"sort.h"
void insert_sort(int *a, int len)
{
	int i,j,tmp;
	for(i = 1; i < len; i++)
	{
		tmp = a[i];
		j = i-1;
		while(j >= 0 && tmp < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

