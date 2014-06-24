#ifndef __BIBLE__
#define __BIBLE__
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define MAX_TXT_LINE 1024*500
#define MAX_WORD 1024*100


typedef struct tagw
{
	char word[32];
	int count;
}Word, *pWord;

typedef struct tag
{
	int word_e_num;
	int char_num;
	int word_num;
	int line_num;
	pWord des_word;
	char *src_txt[MAX_TXT_LINE];
	char *des_txt[MAX_TXT_LINE];
}Txt, *pTxt;

void init(const char *file_name, pTxt b_txt);

void d_space(char *str);

void command_c(char *str, char *left, char *right);

void search_txt(pTxt b_txt, char *right);

void i_space(char *str);
int num_word(char *str);
int num_char(char *str);


#endif
