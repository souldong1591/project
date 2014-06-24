/*************************************************************************
	> File Name: main.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 08:05:03 PM CST
 ************************************************************************/

#include "bible.h"
int main(int argc, char *argv[])
{
	Txt b_txt;
	int i;
	char str[100] = "", left[10] = "", right[100] = "";
	memset(&b_txt, 0, sizeof(Txt));
	init(argv[1], &b_txt);
	printf("e_num : %d\n", b_txt.word_e_num);
	while(fflush(stdin), gets(str) != NULL)
	{
		i_space(str);
		
		if(strncmp(str, "wc -l", 5) == 0)
		{
			printf("Total line: %d lines. \n", b_txt.line_num);
		}
		else if(strncmp(str, "wc -c", 5) == 0)
		{
			printf("Total char: %d char. \n", b_txt.char_num);
		}
		else if(strncmp(str, "wc -w", 5) == 0)
		{
			printf("Total word: %d words. \n", b_txt.word_num);
		}
		else if(strncmp(str, "search", 6) == 0)
		{
			search_txt(&b_txt, str + 7);
		}
		else if(strncmp(str, "top", 3) == 0)
		{
			int top = -1;
			top = atoi(str + 4);
			for(i = 0; i < top && top < b_txt.word_e_num; i++)
			{
				printf("top %d : %s [count: %d]\n", i + 1, b_txt.des_word[i].word, b_txt.des_word[i].count);
			}
		}
	}
	
}
