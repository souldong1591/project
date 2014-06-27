/*************************************************************************
	> File Name: my_reverse.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 26 Jun 2014 10:20:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *str);
void trim_space(char *str);
void reverse_word(char *str, char *l);
int main()
{
	char buf[128];
	char l[128];
	while(memset(buf, 0, 128), memset(l, 0,128), fgets(buf, 128, stdin) != NULL)
	{
		if(buf[0] != '\n')
		{
			trim_space(buf);
			reverse(buf);
			reverse_word(buf, l);
			printf("reverse:\n%s\n", l);
			
		}
		
	}
	return 0;
}

void reverse(char *str)
{
	int bg, end;
	char c;
	bg = 0;
	end = strlen(str) - 1;
	while(bg < end)
	{
		c = str[bg];
		str[bg] = str[end];
		str[end] = c;
		bg++;
		end--;
	}
	
}

void trim_space(char *str)
{
	int i, j;
	for(i = -1, j = 0; j < strlen(str); j++)
	{
		if(str[j] != ' ')
		{
			str[++i] = str[j];
		}
		else if(i != -1 && str[i] != ' ')
		{
			str[++i] = ' ';
		}
	}
	for(; i >= 0; i--)
	{
		if(str[i] != ' ')
		{
			break;
		}
	}
	if(str[i] == '\n')
	{
		str[i] = '\0';
	}
	else
	{
		str[++i] = '\0';
	}
}

void reverse_word(char *str, char *l)
{
	char t[20] = "";
	int word_pos = 0;	
	while(memset(t, 0, 20), sscanf(str + word_pos, "%s", t) > 0)
	{
		word_pos = word_pos + strlen(t) + 1;
		
		reverse(t);

		strcat(l, t);
		l[strlen(l)] = ' ';
	}
	l[strlen(l)] = '\0';
	
}
