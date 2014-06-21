/*************************************************************************
	> File Name: split_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 02:26:20 PM CST
 ************************************************************************/

#include"split.h"
int main(int argc, char *argv[])
{
	pNode list, list1, list2, l, t;
	list = (pNode)calloc(1, sizeof(Node));
	list1 = (pNode)calloc(1, sizeof(Node));
	list2 = (pNode)calloc(1, sizeof(Node));
	list->next = NULL;
	list1->next = NULL;
	list2->next = NULL;
	l = list;
	int num;
	while(fflush(stdin), scanf("%d", &num) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = num;
		t->next = l->next;
		l->next = t;
		l = l->next;
	}
	split_list(&list, &list1, &list2);
	l = list1;
	while(l->next != NULL)
	{
		printf("%d ",l->next->data);
		l = l->next;
	}
	printf("\n");
	l = list2;
	while(l->next != NULL)
	{
		printf("%d ",l->next->data);
		l = l->next;
	}
	printf("\n");
}
