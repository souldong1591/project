/*************************************************************************
	> File Name: logic.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 11:56:24 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	int logic;
	int a = 1;
	int b = 2;
	int c = 3;
	logic = a + b > c && b <= c;
	printf("logic = %d\n", logic);
	logic = a >= b + c || b == c;
	printf("logic = %d\n", logic);
	logic = !(a < c) + b != 1 && (a + c)/2;
	printf("logic = %\n", logic);
}
