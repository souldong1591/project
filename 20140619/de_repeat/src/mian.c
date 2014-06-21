/*************************************************************************
	> File Name: mian.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 07:50:02 PM CST
 ************************************************************************/

#include"de_repeat.h"
int main(int argc, char *argv[])
{
	pNode list, l, t;
	int num;
	list = (pNode)calloc(1, sizeof(Node));
	list->next = NULL;
	l = list;
	printf("List:");
	while(fflush(stdin), scanf("%d", &num) != EOF)
	{
		t = (pNode)calloc(1, sizeof(Node));
		t->data = num;
		t->next = l->next;
		l->next = t;
		l = l->next;
	}
	de_repeat(&list);
	l = list;
	printf("de_repeat:");
	while(l->next != NULL)
	{
		printf("%d ", l->next->data);
		l = l->next;
	}
	return 0;
}
