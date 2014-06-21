/*************************************************************************
	> File Name: bubble_sort.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 12:50:34 PM CST
 ************************************************************************/

#include"sort.h"
void bubble_sort(int *a, int len)
{
	int up,down,tmp;
	int i;
	up = 0;
	down = len - 1;
	while(up < down)
	{
		for(i = up; i < down; i++)
		{
			if(a[i] > a[i+1])
			{
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
			}
		}
		down--;
		for(i = down; i > up; i--)
		{
			if(a[i-1] > a[i])
			{
				tmp = a[i-1];
				a[i-1] = a[i];
				a[i] = tmp;
			}	
		}
		up++;
	}
	
}

