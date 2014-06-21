/*************************************************************************
	> File Name: strstr_main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 19 Jun 2014 11:32:19 AM CST
 ************************************************************************/

#include"my_strstr.h"
int main(int argc, char *argv[])
{
	char str1[50], str2[50], *str;
	printf("enter str1:");
	scanf("%s",str1);
	printf("enter str2:");
	scanf("%s",str2);
	str = strstr_fun(str1, str2);
	printf("%c\n",*str);
	return 0;
}
