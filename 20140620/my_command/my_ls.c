/*************************************************************************
	> File Name: my_ls.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 20 Jun 2014 11:39:21 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
void for_time(char *str_time);
void mode_str(mode_t st_mode, char *str_mode);
int main(int argc, char *argv[])
{
	DIR *pDir;
	struct dirent *myent;
	struct stat mystat;
	char str_mode[11] = "";
	char pathname[100];
	char *str_time;
	if(argc == 1)
	{
		pDir = opendir(".");
	}
	else
	{
		pDir = opendir(argv[1]);
	}
	if(pDir == NULL)
	{
		perror("open dir:");
		exit(-1);
	}
	while((myent = readdir(pDir)) != NULL)
	{
		memset(&mystat, 0, sizeof(mystat));
		if(argc == 1)
		{
			strcpy(pathname, getcwd(NULL, 0));
		}
		else
		{
			strcpy(pathname, argv[1]);
		}
		strcat(pathname, "/");
		strcat(pathname, myent->d_name);
		stat(pathname, &mystat);
		memset(str_mode, 0, 11);
		mode_str(mystat.st_mode, str_mode);
		str_time = ctime(&mystat.st_atime);
		for_time(str_time);
		if(strncmp(myent->d_name,".",1) != 0)
		{
			printf("%s. %d %-5s %-5s %5d %s %s\n", str_mode, 
				mystat.st_nlink,getpwuid(mystat.st_uid)->pw_name,getgrgid(mystat.st_gid)->gr_name, 
				mystat.st_size, str_time + 4, myent->d_name);
		}
	}
	return 0;
}

void for_time(char *str_time)
{
	char *s;
	s = str_time;
	while(*s)
	{
		s++;
	}
	while(*s != ':')
	{
		s--;
	}
	*s = '\0';
}

void mode_str(mode_t st_mode, char *str)
{
	strcpy(str, "----------");
	if(S_ISDIR(st_mode))
	{
		str[0] = 'd';
	}
	if(S_IRUSR & st_mode)
	{
		str[1] = 'r';
	}
	if(S_IWUSR & st_mode)
	{
		str[2] = 'w';
	}
	if(S_IXUSR & st_mode)
	{
		str[3] = 'x';
	}
	if(S_IRGRP & st_mode)
	{
		str[4] = 'r';
	}
	if(S_IWGRP & st_mode)
	{
		str[5] = 'w';
	}
	if(S_IXGRP & st_mode)
	{
		str[6] = 'x';
	}
	if(S_IROTH & st_mode)
	{
		str[7] = 'r';
	}
	if(S_IWOTH & st_mode)
	{
		str[8] = 'w';
	}
	if(S_IXOTH & st_mode)
	{
		str[9] = 'x';
	}
}
