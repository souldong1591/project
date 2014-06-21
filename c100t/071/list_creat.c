/*************************************************************************
	> File Name: list_creat.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 11:53:31 PM CST
 ************************************************************************/

#include<stdio.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;

void creat(pNode *list)
{
	int data;
	pNode t, p;
	p = *list;
	while(fflush(stdin), scanf("%d", &data) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = data;
		t->next = p->next;
		p->next = t;
		p = p->next;
	}

}

int main(int argc, char *argv[])
{
	pNode list;
	list = (pNode)calloc(1, sizeof(Node));
	list->next = NULL;
	creat(&list);
	while(list->next != NULL)
	{
		printf("%d ", list->next->data);
		list = list->next;
	}
	printf("\n");
	return 0;
}
