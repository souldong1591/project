/*************************************************************************
	> File Name: sort_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 18 Jun 2014 01:55:10 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	int i;
	int *a;
	a = (int*)calloc(1,sizeof(int));
	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	show_sort("Before", a, 10);
	bubble_sort(a,10);
	show_sort("bubble", a, 10);

	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,10);
	show_sort("quick", a, 10);

	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	select_sort(a,10);
	show_sort("select", a, 10);

	for(i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	insert_sort(a,10);
	printf("insert sort:");
	show_sort("insert", a, 10);
	return 0;
}
