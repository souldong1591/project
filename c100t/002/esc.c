/*************************************************************************
	> File Name: esc.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 10:12:52 PM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc, char *argv[])
{
	printf("How are you ?\n");
	printf("I am fine.\n\n");

	printf("How are you ?\t");
	printf("I am fine.\n\n");

	printf("How are you ?\n");
	printf("\bI am fine.\n\n");

	printf("                I am fine.");
	printf("\rHow are you ?\n\n");

	printf("note:\n  a s\ti\b\bk\rp\n");
	return 0;
}
