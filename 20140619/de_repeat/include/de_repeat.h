#ifndef __DE_REPEAT__
#define __DE_REPEAT__
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;


void de_repeat(pNode *list);

#endif
