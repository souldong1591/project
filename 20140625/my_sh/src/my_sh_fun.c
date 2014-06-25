/*************************************************************************
	> File Name: my_sh_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 08:01:39 PM CST
 ************************************************************************/

#include "my_sh.h"

void trim_space(char *str)
{
	int i, j;
	for(i = -1, j = 0; j < strlen(str); j++)
	{
		if(str[j] != ' ')
		{
			str[++i] = str[j];
		}
		else
		{
			if(i != -1 && str[i] != ' ')
			{
				str[++i] = ' ';
			}
		}
	}
	while(i >= 0)
	{
		if(str[i] != ' ')
		{
			break;
		}
		i--;
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

void del_command(char *str, char *arglist[])
{
	int i = 0, j = 0, k = 0;
	arglist[0] = (char*)calloc(1, 20);
	while(str[i] != '\0')
	{
		k = 0;
		while(str[i] != ' ' && str[i] != '\0')
		{
			arglist[j][k] = str[i];
			i++;
			k++;
		}
		if(str[i] == ' ')
		{
			
			j++;
			arglist[j] = (char *)calloc(1, 20);

		}
		if(str[i] == '\0')
		{
			break;
		}
		i++;
	}

	
	arglist[++j] = (char *)calloc(1, 20);
	arglist[j] = NULL;

}


void path_name(char *str)
{
	int i = 0, j = 0;
	getcwd(str, 50);
	if(str[i] == '/' && str[i+1] == '\0')
	{
		return;
	}
	else
	{
		while(str[i] != '\0')
		{
			i++;
		}
		while(str[i] != '/')
		{
			i--;
		}
		i++;
		while(str[i] != '\0')
		{
			str[j] = str[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}



}
