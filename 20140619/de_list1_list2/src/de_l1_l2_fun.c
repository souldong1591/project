/*************************************************************************
	> File Name: de_l1_l2_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 11:44:58 AM CST
 ************************************************************************/

#include"delete_l1_l2.h"
void de_l1_l2(pNode *list1, pNode *list2)
{
	pNode l1, l2, t;
	l1 = *list1;
	while(l1->next != NULL)
	{
		l2 = *list2;
		while(l2->next != NULL)
		{
			if(l1->next->data == l2->next->data)
			{
				t = l1->next;
				l1->next = t->next;
				free(t);
			}
			l2 = l2->next;
		}
		l1 = l1->next;
	}
}
