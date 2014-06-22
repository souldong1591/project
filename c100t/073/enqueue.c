/*************************************************************************
	> File Name: enqueue.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 21 Jun 2014 10:49:50 PM CST
 ************************************************************************/

#include<stdio.h>
typedef struct Enqueue
{
	int data;
	struct Enqueue *next;
}Node, *pNode;

void init(pNode *que)
{
	*que = (pNode)calloc(1, sizeof(Node));
	(*que)->next = NULL;
}

void insert(pNode *que)
{
	pNode p, t;
	int data;
	p = *que;
	while(fflush(stdin), scanf("%d", &data) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = data;
		t->next = p->next;
		p->next = t;
		p = p->next;

	}

}

void out(pNode *que)
{
	pNode p, t;
	p = *que;
	t = (pNode)calloc(1, sizeof(Node));
	t = p->next;
	p->next = t->next;
	free(t);

}

void show(pNode *que)
{
	pNode p;
	p = *que;
	while(p->next != NULL)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	pNode que;
	init(&que);
	insert(&que);
	show(&que);
	out(&que);
	show(&que);
	return 0;
}

