/*************************************************************************
	> File Name: my_sh.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 25 Jun 2014 08:02:38 PM CST
 ************************************************************************/

#include "my_sh.h"

int main(int argc, char *argv[])
{
	char u_name[20] = "", local_name[30] = "";
	char line[100] = "";
	char path[50] = "";
	char **arglist;
	int iret;
	
	system("clear");
	while(1)
	{
		memset(u_name, 0, 20);
		memset(local_name, 0, 30);
		memset(path, 0, 50);
		strcpy(u_name, getpwuid(getuid())->pw_name);
		gethostname(local_name, sizeof(char)*30);
		path_name(path);
		printf("[%s@%s %s]$ ", u_name, local_name, path);
		
		while(fgets(line, 100 , stdin))
		{
			if(line[0] == '\n')
			{
				break;
			}
			else
			{
				trim_space(line);				
				del_command(line, arglist);
				
				if(fork() > 0)
				{
					wait(NULL);
					break;	
				}
				else
				{
					iret = execvp(arglist[0], arglist);
					if(iret == -1)
					{
						printf("error!\n");
					}
					exit(0);
					
				}
				

			}
		}
	

	}

	return 0;
}
