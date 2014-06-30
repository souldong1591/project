/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 27 Jun 2014 04:47:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int num)
{
	wait();
	exit(0);
}

int main(int argc, char *argv[])
{
	int pid, fd_server, fd_w, fd_r;
	char buf[1024] = "";
	char fifo_r_name[32] = "";
	char fifo_w_name[32] = "";
	
	//判断传参数量是否正确
	if(argc != 2)
	{
		printf("USAGE: EXE PIPENAME\n");
		exit(-1);
	}

	//打开服务器管道，并将自己的进程id发送给服务器
	fd_server = open(argv[1], O_WRONLY);
	if(fd_server == -1)
	{
		perror("open");
		exit(-1);
	}

	//创建并打开自己专用的收发消息管道
	sprintf(fifo_r_name, "%d_r.fifo", getpid());
	sprintf(fifo_w_name, "%d_w.fifo", getpid());
	mkfifo(fifo_r_name, 0666);
	mkfifo(fifo_w_name, 0666);
	FILE *fp = fdopen(fd_server, "w");
	fprintf(fp, "%d", getpid());
	fflush(fp);
	fd_r = open(fifo_r_name, O_RDONLY);
	fd_w = open(fifo_w_name, O_WRONLY);
	printf("id: %d, begin to talk !\n", getpid());

	//fork子进程    父进程发    子进程收
	if((pid = fork()) > 0)
	{
		//注册信号
		signal(17,handler);

		//关闭读
		close(fd_r);

		//发消息
		FILE *fp_w = fdopen(fd_w, "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			fprintf(fp_w, "From %d: %s", getpid(), buf);
			fflush(fp_w);
		}

		//当ctrl+d结束循环时， 给主机bye， 并将子进程结束
		fprintf(fp_w, "bye");
		fflush(fp_w);
		kill(pid, 9);
		close(fd_w);

		//删除自己的专用管道
		unlink(fifo_r_name);
		unlink(fifo_w_name);
		
		//防止父进程结束
		while(1);
	}
	else
	{
		close(fd_w);

		//收消息
		while(memset(buf, 0, 1024), read(fd_r, buf, 1024) > 0)
		{
			write(1, buf, strlen(buf));
		}

		close(fd_r);
	}
	

	return 0;
}
