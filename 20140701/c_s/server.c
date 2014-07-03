/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 01 Jul 2014 07:04:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>


void* pthread_fun(void* arg);
void d_str(char *str, char *left, char *right);

int main(int argc, char *argv[])
{
	int fd_server;
	char buf[1024] = "";

	if(argc != 2)
	{
		printf("USAGE: EXE PIPENAME\n");
		exit(-1);
	}
	
	fd_server = open(argv[1], O_RDONLY);
	if(fd_server == -1)
	{
		perror("open");
		exit(-1);
	}

	while(memset(buf, 0, 1024), read(fd_server, buf, 1024) > 0)
	{
		printf("1:%s\n", buf);
		pthread_t pthid;
		pthread_create(&pthid, NULL, pthread_fun, (void*)buf);
		
		
	}
	return 0;

}

void* pthread_fun(void* arg)
{
	int c_pid, fd_w, fd_r;
	char buf[1024] = "";
	char left[16] = "", right[1024] = "";
	char fifo_w_name[32] = "";
	char *recv;
	recv = (char *)arg;
	printf("2:%s\n", recv);
	
	pthread_detach(pthread_self());

	d_str(recv, left, right);
	c_pid = atoi(left);
	sprintf(fifo_w_name, "%d.fifo", c_pid);
	fd_w = open(fifo_w_name, O_WRONLY);

	FILE* fp_r;
	fp_r = fopen(right, "r");
	if(fp_r == NULL)
	{
		perror("open");
		pthread_exit((void*)0);
	}
	while(memset(buf, 0, 1024), fread(buf, 1, 1024, fp_r) > 0)
	{
		write(fd_w, buf, sizeof(buf));
	}
	fclose(fp_r);
	close(fd_w);

}

void d_str(char *str, char *left, char *right)
{
	int i = 0, j = 0, k = 0;
	while(str[i] != ' ')
	{
		left[j] = str[i];
		i++;
		j++;
	}
	left[j] = '\0';
	i++;
	while(str[i] != '\0')
	{
		right[k] = str[i];
		k++;
		i++;
	}
	right[k] = '\0';
	puts(left);
	puts(right);
}

