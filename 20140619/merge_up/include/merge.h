#ifndef __MERGE__
#define __MERGE__
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;

void merge_up(pNode *list1, pNode *list2);

#endif
