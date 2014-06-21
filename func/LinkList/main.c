/*************************************************************************
	> File Name: main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 08:30:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"
int main(int argc, char *argv[])
{
	int data;
	pNode list;
	list_init(&list);
	while(fflush(stdin), scanf("%d", &data) != EOF)
	{
		list_t_insert(&list, data);
	}
	printf("List:");
	list_show(&list);
	return 0;
}
