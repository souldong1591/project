/*************************************************************************
	> File Name: main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 08:47:35 PM CST
 ************************************************************************/

#include"doub2str.h"
int main(int argc, char *argv[])
{
	double num;
	char str[30];
	printf("enter double num:");
	scanf("%lf", &num);
	doub2str(num, str);
	puts(str);
	return 0;
}
