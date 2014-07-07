/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 05 Jul 2014 03:34:22 PM CST
 ************************************************************************/

#include "pool_udp.h"
int make_child(pCHLD arr, int cnt );
void child_main();
int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		printf("USAGE: EXE IP PORT CNT\n");
		exit(-1);
	}

	int chld_cnt = atoi(argv[3]), max_fd, i;
	pCHLD chlds = (pCHLD)calloc(chld_cnt, sizeof(CHLD));
	max_fd = make_child(chlds, chld_cnt);
printf("max %d\n",max_fd);
	int fd_server;
	SA server_addr;
	bzero(&server_addr, sizeof(SA));
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == bind(fd_server, (struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}

	fd_set read_set, ready_set;
	FD_ZERO(&read_set);
	FD_SET(fd_server, &read_set);
	max_fd = max_fd > fd_server ? max_fd : fd_server;
	for(i = 0; i < chld_cnt; i++)
	{
		FD_SET(chlds[i].s_read, &read_set);
	}
	struct timeval tm;
	while(1)
	{
		tm.tv_usec = 1000;
		tm.tv_sec = 0;
		ready_set = read_set;
		select(max_fd + 1, &ready_set, NULL, NULL, NULL);
		printf("select \n");
		if(FD_ISSET(fd_server, &ready_set))
		{
			char buf[1024] = "";
			SA from_addr;
			int addrlen = sizeof(SA);
			bzero(&from_addr, sizeof(SA));
			recvfrom(fd_server, buf, 1024, 0, (struct sockaddr*)&from_addr, &addrlen);
			for(i = 0; i < chld_cnt; i++)
			{
				if(chlds[i].s_flag == S_IDLE)
				{
					break;
				}
			}
			if(i == chld_cnt)
			{
			
			}
			else
			{
				chlds[i].s_flag = S_BUSY;
				chlds[i].s_cnt ++;
				FILE* fp = fdopen(chlds[i].s_write, "w");
				printf("h\n");
				fprintf(fp, "%d %d %s", from_addr.sin_port, from_addr.sin_addr.s_addr, buf);
				fflush(fp);
			}
		}
		for(i = 0; i < chld_cnt; i++)
		{
			char c;
			if(FD_ISSET(chlds[i].s_read, &ready_set))
			{
				read(chlds[i].s_read, &c, 1);
				chlds[i].s_flag = S_IDLE;

			}
		}
	}
	return 0;
	

}
int make_child(pCHLD arr, int cnt )
{
	int i, max_fd = 0x80000000;
	for(i = 0; i < cnt; i++)
	{
		pid_t pid;
		int fds1[2], fds2[2];
		pipe(fds1);     //0 pr   1 cw
		pipe(fds2);     //0 cr   1 pw
		pid = fork();
		if(pid == 0)
		{
			close(fds1[0]);
			close(fds2[1]);
			dup2(fds2[0], 0);
			dup2(fds1[1], 1);
			child_main();
			exit;
		}
		else
		{
			close(fds1[1]);
			close(fds2[0]);
			arr[i].s_pid = pid;
			arr[i].s_flag = S_IDLE;
			arr[i].s_read = fds1[0];
			if(fds2[1] > max_fd)
			{
				max_fd = fds1[0];
			}
			arr[i].s_write = fds2[1];
		}

	}
	return max_fd;
	
}

void child_main()
{
	SA client_addr;
	int fd_socket;
	char buf[1024];
	while(1)
	{
		bzero(&client_addr, sizeof(SA));
		bzero(buf, 1024);
		client_addr.sin_family = AF_INET;
		scanf("%d %d %s", &(client_addr.sin_port), &(client_addr.sin_addr.s_addr), buf);
		fd_socket = socket(AF_INET, SOCK_DGRAM, 0);
		sendto(fd_socket, buf, strlen(buf), 0, (struct sockaddr*)&client_addr, sizeof(SA));
		printf("1");
		fflush(stdout);

	}
}
