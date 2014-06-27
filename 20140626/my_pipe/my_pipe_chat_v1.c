/*************************************************************************
	> File Name: my_pipe_chat_v1.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 26 Jun 2014 03:24:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fds_p[2], fds_c[2];
	char buf[1024] = "";

	pipe(fds_p);
	pipe(fds_c);
	if(fork() > 0)
	{
		close(fds_p[1]);
		close(fds_c[0]);
		
		while(memset(buf, 0, 1024), read(fds_p[0], buf, 1024) > 0)
		{
			write(1, buf, strlen(buf));
		}
		close(fds_p[0]);

		FILE *fp = fdopen(fds_c[1], "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			if(buf[0] != '\n')
			{
				fprintf(fp, "From p:%s", buf);
				fflush(fp);
			}
		}
		close(fds_c[1]);

		wait(NULL);

	}
	else
	{
		close(fds_p[0]);
		close(fds_c[1]);
		
		FILE *fp = fdopen(fds_p[1], "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			
				fprintf(fp, "From c:%s", buf);
				fflush(fp);
			
		}
		close(fds_p[1]);

		printf("begin\n");
		while(memset(buf, 0, 1024), read(fds_c[0], buf, 1024) > 0)
		{
			write(1, buf, strlen(buf));
		}
		close(fds_c[0]);
		
		exit(-1);
	}

	return 0;
}
