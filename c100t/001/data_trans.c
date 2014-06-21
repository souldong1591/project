/*************************************************************************
	> File Name: data_trans.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 09:55:56 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	int a = 5;
	char c = 'a';
	float f = 5.3;
	double m = 12.65;
	double result;
	printf("a + c = %d\n", a + c);
	printf("a + c = %c\n", a + c);
	printf("f + m = %f\n", f + m);

	printf("a + m = %f\n", a + m);
	printf("c + f = %f\n", c + f);
	
	result = a + c * (f + m);
	printf("double = %f\n", result);
	return 0;

}
