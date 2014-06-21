#ifndef __DELETE_L1_L2__
#define __DELETE_L1_L2__
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;

void de_l1_l2(pNode *list1, pNode *list2);

#endif
