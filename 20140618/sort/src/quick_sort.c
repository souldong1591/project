/*************************************************************************
	> File Name: quick_sort.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 01:02:32 PM CST
 ************************************************************************/

#include"sort.h"

int partition(int *a, int len)
{
	int low,high;
	int pivot,tmp;
	low = 0;
	high = len - 1;
	pivot = a[0];
	while(low < high)
	{
		while(low < high && a[high] >= pivot)
		{
			high--;
		}
		if(low < high)
		{
			tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		}
		while(low < high && a[low] < pivot)
		{
			low++;
		}
		if(low < high)
		{
			tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		}
	}
	return low;
}

void quick_sort(int *a, int len)
{
	int pivot;
	if(len <= 5)
	{
		insert_sort(a, len);
	}
	else
	{
		pivot = partition(a, len);
		quick_sort(a, pivot);
		quick_sort(&a[pivot + 1], len - pivot - 1);
	}
}
