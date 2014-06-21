/*************************************************************************
	> File Name: merge_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 05:19:52 PM CST
 ************************************************************************/

#include"merge.h"
int main(int argc, char *argv[])
{
	pNode list1, list2, l1, l2, t;
	int num;
	list1 = (pNode)calloc(1, sizeof(Node));
	list2 = (pNode)calloc(1, sizeof(Node));
	list1->next = NULL;
	list2->next = NULL;
	l1 = list1;
	l2 = list2;
	printf("list1:");
	while(fflush(stdin), scanf("%d",&num) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = num;
		t->next = l1->next;
		l1->next = t;
		l1 = l1->next;
	}
	printf("list2:");
	while(fflush(stdin), scanf("%d",&num) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = num;
		t->next = l2->next;
		l2->next = t;
		l2 = l2->next;
	}
	merge_up(&list1, &list2);
	l1 = list1;
	printf("Merge:");
	while(l1->next != NULL)
	{
		printf("%d ",l1->next->data);
		l1 = l1->next;
	}
	return 0;
}
