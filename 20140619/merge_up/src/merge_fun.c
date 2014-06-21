/*************************************************************************
	> File Name: merge_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 02:50:12 PM CST
 ************************************************************************/

#include"merge.h"
void merge_up(pNode *list1, pNode *list2)
{
	pNode l1, l2, t;
	l1 = *list1;
	l2 = *list2;
	while(l2->next != NULL)
	{
		l1 = *list1;
		while(l1->next != NULL)
		{
			if(l2->next->data < l1->next->data)
			{
				t = l2->next;
				l2->next = t->next;
				t->next = l1->next;
				l1->next = t;
				break;
			}
			l1 = l1->next;
		}
		if(l1->next == NULL)
		{
			t = l2->next;
			l2->next = t->next;
			t->next = l1->next;
			l1->next = t;
		}
	}
}
