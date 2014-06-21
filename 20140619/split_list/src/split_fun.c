/*************************************************************************
	> File Name: split_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 02:12:21 PM CST
 ************************************************************************/

#include"split.h"

void split_list(pNode *list, pNode *list1, pNode *list2)
{
	pNode t, l, l1, l2;
	int flag = 0;
	l = *list;
	l1 = *list1;
	l2 = *list2;
	while(l->next != NULL)
	{
		if(flag == 0)
		{
			t = l->next;
			t->next = l1->next;
			l1->next = t;
			l1 = l1->next;
			flag = 1;
		}
		else if(flag == 1)
		{
			t = l->next;
			t->next = l2->next;
			l2->next = t;
			l2 = l2->next;
			flag = 0;
		}
		l = l->next;
	}

}

