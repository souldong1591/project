#ifndef __SPLIT__
#define __SPLIT__
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next; 
}Node, *pNode;

void split_list(pNode *list, pNode *list1, pNode *list2);

#endif
