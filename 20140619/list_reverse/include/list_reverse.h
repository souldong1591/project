#ifndef __LIST_REVERSE__
#define __LIST_REVERSE__
#include<stdio.h>
#include<stdlib.h>
typedef struct LINK_LIST	
{
	int data;
	struct LINK_LIST *next;
}Node,*pNode;

void list_reverse(pNode *list);
void list_show(pNode *list);
#endif
