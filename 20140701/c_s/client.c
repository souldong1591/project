/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 01 Jul 2014 08:55:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void trim_space(char *str);

int main(int argc, char *argv[])
{
	int fd_server, fd_r;
	char buf[1024] = "";
	char fifo_r_name[32] = "";
	char s_buf[1024] = "";
	
	if(argc != 2)
	{
		printf("USAGE: EXE PIPENAME\n");
		exit(-1);
	}

	fd_server = open(argv[1], O_WRONLY);
	if(fd_server == -1)
	{
		perror("open");
		exit(-1);
	}

	sprintf(fifo_r_name, "%d.fifo", getpid());
	mkfifo(fifo_r_name, 0666);
	
printf("c\n");	
	while(memset(buf, 0, 1024), memset(s_buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
	{
		sprintf(s_buf, "%d", getpid());
		trim_space(buf);
		strcat(s_buf, " ");
		strcat(s_buf, buf);
		puts(s_buf);	
		write(fd_server, s_buf, sizeof(s_buf));
		fd_r = open(fifo_r_name, O_RDONLY);

		char recv[1024];
		while(memset(recv, 0, 1024), read(fd_r, recv, 1024) > 0)
		{
			write(1, recv, sizeof(recv));
		}
	}
	close(fd_r);
	close(fd_server);

	return 0;
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
