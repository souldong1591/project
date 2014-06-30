/*************************************************************************
	> File Name: sum.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 28 Jun 2014 03:29:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int fun(int a)
{
	int i, sum = 0;
	for(i = 1; i <= a; i++)
	{
		sum += i;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int i = 0;
	int a = 10;
	int sum = fun(a);
	printf("sum is : %d\n", sum);
	return 0;	
}
