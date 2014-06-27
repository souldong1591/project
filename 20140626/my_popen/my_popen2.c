/*************************************************************************
	> File Name: my_popen2.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 26 Jun 2014 09:34:25 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[128] = "";
	
	fp = popen("./my_reverse", "w");
	while(memset(buf, 0, 128), fgets(buf, 128, stdin) != NULL)
	{
		if(buf[0] != '\n')
		{
			fprintf(fp, "%s", buf);
			fflush(fp);
		}
	}
	

	return 0;
}

