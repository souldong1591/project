/*************************************************************************
	> File Name: show_sort.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 08:31:02 PM CST
 ************************************************************************/

#include"sort.h"
void show_sort(char *s, int *a, int len)
{
	int i;
	printf("%s:",s);
	for(i = 0; i < len; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}
