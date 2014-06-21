/*************************************************************************
	> File Name: de_depeat.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 07:43:03 PM CST
 ************************************************************************/

#include"de_repeat.h"
void de_repeat(pNode *list)
{
	pNode l, t;
	l = *list;
	while(l->next->next != NULL)
	{
		if(l->next->data == l->next->next->data)
		{
			t = l->next->next;
			l->next = t->next;
			free(t);

		}
		l = l->next;
	}
}
