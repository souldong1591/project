/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 27 Jun 2014 08:16:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM 500

//结构体：用来存储上线加入对话的客户端进程
typedef struct tag
{
	int c_read;
	int c_write;
}Client_Node;

int main(int argc, char *argv[])
{
	int fd_server, fd_r, fd_w, c_pid, i;
	char buf[1024] = "";
	char fifo_r_name[32] = "";
	char fifo_w_name[32] = "";
	struct timeval tm;
	fd_set read_set, ready_set;
	Client_Node c_info[NUM];
	memset(c_info, -1, sizeof(c_info));
	
	//判断传参数量是否正确
	if(argc != 2)
	{
		printf("USAGE: EXE PIPENAME\n");
		exit(-1);
	}

	//打开服务器管道
	fd_server = open(argv[1], O_RDONLY);

	//初始化raed_set,并将fd_server加入集合
	FD_ZERO(&read_set);
	FD_SET(fd_server, &read_set);
	
	//对服务器管道进行监听
	while(1)
	{
		//定义select等待时间
		tm.tv_sec = 0;
		tm.tv_usec = 1000;
		
		ready_set = read_set;
		select(1024, &ready_set, NULL, NULL, &tm);

		//判断是否有客户端进程上线
		if(FD_ISSET(fd_server, &ready_set))
		{
			memset(buf, 0, 1024);
			
			//读取客户端进程从服务器管道发来的信息
			if(read(fd_server, buf, 1024) == 0)
			{
				continue;
			}
			c_pid = atoi(buf);
			printf("client %d on !\n", c_pid);

			//根据客户端发来的进程信息，打开客户端进程自己专用的收发消息管道
			sprintf(fifo_w_name, "%d_r.fifo", c_pid);
			sprintf(fifo_r_name, "%d_w.fifo", c_pid);
			fd_w = open(fifo_w_name, O_WRONLY);
			fd_r = open(fifo_r_name, O_RDONLY);

			//遍历，将新来的客户端进程存入c_info结构体中
			for(i = 0; i < NUM; i++)
			{
				if(c_info[i].c_read == -1)
				{
					break;
				}
			}
			if(i < NUM)
			{
				c_info[i].c_read = fd_r;
				c_info[i].c_write = fd_w;
			}
			else
			{
				//当结构体已满，结束此客户端进程并删除其管道
				kill(c_pid, 9);
				close(fd_r);
				close(fd_w);
				unlink(fifo_r_name);
				unlink(fifo_w_name);
			}
			
			//将fd_r加入集合
			FD_SET(fd_r, &read_set);

		}

		//遍历，对客户端发的消息进行监听检测，若有转发给所以客户端进程
		for(i = 0; i < NUM; i++)
		{
			//若有进程发消息
			if(FD_ISSET(c_info[i].c_read, &ready_set))
			{
				//读取客户端进程发来的消息
				char recvbuf[1024] = "";
				read(c_info[i].c_read, recvbuf, 1024);

				//若消息为bye，则关闭其管道，将其从集合中清除，并置其所占结构体为-1
				if(strncmp(recvbuf, "bye", 3) == 0)
				{
					printf("a client off\n");
					close(c_info[i].c_read);
					close(c_info[i].c_write);
					FD_CLR(c_info[i].c_read, &read_set);
					memset(c_info + i, -1, sizeof(Client_Node));
				}
				else		//否则，将消息转发给所有在线客户端进程
				{
					int j;
					for(j = 0; j < NUM; j++)
					{
						if(c_info[j].c_write != -1)
						{
							write(c_info[j].c_write, recvbuf, strlen(recvbuf));
						}
					}
				}
			}
		}

	}
	return 0;
}
