/*************************************************************************
	> File Name: list_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 21 Jun 2014 12:02:23 AM CST
 ************************************************************************/

#include<stdio.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}Node, *pNode;
void creat(pNode *list)
{
	pNode p, t;
	int data;
	*list = (pNode)calloc(1, sizeof(Node));
	(*list)->next ==NULL;
	p = *list;
	while(fflush(stdin), scanf("%d", &data) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = data;
		t->next = p->next;
		p->next = t;
	}
}

void delete(pNode *list, int data)
{
	pNode p, t;
	p = *list;
	int flag =0;
	if(p->next == NULL)
	{
		printf("list is NULL!\n");
		return ;
	}
	while(p->next != NULL)
	{
		if(p->next->data == data)
		{
			t = p->next;
			p->next = t->next;
			free(t);
			flag = 1;
		}
		p = p->next;
	}
	if(flag == 0)
	{
		printf("no!\n");
	}
}

void show(pNode *list)
{
	pNode p;
	p = *list;
	while(p->next != NULL)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
}
int main(int argc, char *argv[])
{
	pNode list;
	int data;
	creat(&list);
	show(&list);
	printf("Please enter delete data:");
	scanf("%d", &data);

	delete(&list, data);
	show(&list);
	return 0;

}
