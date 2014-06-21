/*************************************************************************
	> File Name: my_pwd.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 09:55:12 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	printf("%s\n", getcwd(NULL, 0));
	return 0;
}
