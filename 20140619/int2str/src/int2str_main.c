/*************************************************************************
	> File Name: int2str_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 10:52:20 AM CST
 ************************************************************************/

#include"int2str.h"
int main(int argc, char *argv[])
{
	int a;
	int i = 0;
	char s[20];
	printf("in:");
	scanf("%d", &a);
	int2str(a, s);
	printf("out:");
	puts(s);
	return 0;
}
