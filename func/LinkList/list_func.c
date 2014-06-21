/*************************************************************************
	> File Name: list_func.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 08:15:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void list_init(pNode *list)
{
	*list = (pNode)calloc(1, sizeof(Node));
	(*list)->next = NULL;
}

void list_h_insert(pNode *list, int data)
{
	pNode p, t;
	p = *list;
	t = (pNode)calloc(1, sizeof(Node));
	t->data = data;
	t->next = p->next;
	p->next = t;
}

void list_t_insert(pNode *list,  int data)
{
	pNode p, t;
	p = *list;
	while(p->next != NULL)
	{
		p = p->next;
	}
	t = (pNode)calloc(1, sizeof(Node));
	t->data = data;
	t->next = p->next;
	p->next = t;
}

void list_show(pNode *list)
{
	pNode p;
	p = *list;
	while(p->next != NULL)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}
