/*************************************************************************
	> File Name: init.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 05:11:37 PM CST
 ************************************************************************/

#include "bible.h"

int word_cmp(const void* left, const void* right);
void init(const char *filename, pTxt b_txt)
{
	int fd_r, read_n;
	int i = 0, j = 0, k = 0, m = 0, n = 0, word_pos = 0, flag = 1;
	char str[1024] = "", word[32] = "";
	fd_r = open(filename, O_RDONLY);
	if(fd_r == -1)
	{
		perror("fail:");
		exit(-1);
	}
	while(memset(str, 0, 1024), (read_n = read(fd_r, str, 1024)) > 0)
	{
		i = 0;
		while(str[i] != '\0')
		{
			
			b_txt->src_txt[j] = (char *)calloc(1, 1024);
			b_txt->des_txt[j] = (char *)calloc(1, 1024); 
			while(str[i] != '\n' && str[i] != '\0')
			{
				b_txt->src_txt[j][k] = str[i];
				if(isupper(str[i]) != 0)
				{
					b_txt->des_txt[j][k] = str[i] +32;
				}
				else if(isalnum(str[i]) == 0)
				{
					b_txt->des_txt[j][k] = ' ';
				}
				else
				{
					b_txt->des_txt[j][k] = str[i];
				}
			
				i++;
				k++;
			
			}
			if(str[i] == '\n')
			{
					
				
				i_space(b_txt->des_txt[j]);
				puts(b_txt->des_txt[j]);
				b_txt->char_num = b_txt->char_num + num_char(b_txt->src_txt[j]);
				b_txt->word_num = b_txt->word_num + num_word(b_txt->des_txt[j]);
					
				b_txt->des_word = (pWord)calloc(1, MAX_WORD*sizeof(Word));
				word_pos = 0;
				//printf("%s\n", b_txt->des_txt[j]);
			/*	while(memset(word, 0, 32), sscanf(b_txt->des_txt[j] + word_pos, "%s", word) == 1)
				{
					word_pos = word_pos + strlen(word) + 1;
				//	printf("%s\n", word);	
					for(m = 0; m < b_txt->word_e_num; m++)
					{
						if(strcmp(b_txt->des_word[m].word, word) == 0)
						{
							b_txt->des_word[m].count++;	
							break;
						}
					}
					if(m >= b_txt->word_e_num)
					{
						b_txt->word_e_num++;
						strcpy(b_txt->des_word[m].word, word);
						b_txt->des_word[m].count++;
					}
		
				} */
			


				k = 0;
				j++;
			}
			i++;
		}
	
		
	}
	b_txt->line_num = j;
//	qsort(b_txt->des_word, b_txt->word_e_num, sizeof(MAX_WORD), word_cmp);

}

void i_space(char *str)
{
	int i, j = 0;
	for(i = -1, j = 0; j < strlen(str); j++)
	{
		if(str[j] == ' ')
		{
			if(i != -1 && str[i] != ' ')
			{
				str[++i] = ' ';
			}
		}
		else
		{
			str[++i] = str[j];
		}
	}
	for(; i >= 0; i--)
	{
		if(str[i] != ' ')
		{
			break;
		}
	}
	str[++i] = '\0';

}

int num_word(char *str)
{
	int i, num = 0;
	char pre = ' ';
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] != ' ' && pre == ' ')
		{
			num++;
		}
		pre = str[i];
	}
	return num;
}

int num_char(char *str)
{
	int i = 0, num = 0;
	while(str[i] != '\0')
	{
		if(str[i] != ' ')
		{
			num++;
		}
		i++;
	}
	return num;
}

int word_cmp(const void* left, const void* right)
{
	pWord word_left, word_right;
	int count_left, count_right;
	word_left = (pWord)left;
	word_right = (pWord)right;
	count_left = word_left->count;
	count_right = word_right->count;
	if(count_right > count_left)
	{
		return 1;
	}
	else if(count_right == count_left)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

