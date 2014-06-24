/*************************************************************************
	> File Name: search.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 24 Jun 2014 09:09:50 AM CST
 ************************************************************************/

#include "bible.h"
void search_txt(pTxt b_txt, char *right)
{
	int i = 0;
	for(i = 0; i < b_txt->line_num; i++)
	{
		if(strstr(b_txt->des_txt[i], right) != NULL)
		{
			printf("line: %d, detail: %s\n", i, b_txt->src_txt[i]);
		}
	}
}
