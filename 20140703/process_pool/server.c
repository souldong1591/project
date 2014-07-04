/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 03 Jul 2014 07:33:41 PM CST
 ************************************************************************/

#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("USAGE: EXE IP PORT CNT\n");
		exit(-1);
	}
	int fd_server,i;
	fd_set read_set, ready_set;
	pChild my_childs = (pChild)calloc(atoi(argv[3]), sizeof(Child));
	make_child(my_childs, atoi(argv[3]));
	fd_server = listenfd_init(argv[1], argv[2]);
	FD_ZERO(&read_set);
	FD_SET(fd_server, &read_set);
	for(i = 0; i < atoi(argv[3]); i++)
	{
		FD_SET(my_childs[i].s_read. &read_set);
	}
	struct timeval tm;
	while(1)
	{
		tm.tv_usec = 1000;
		tm.tv_sec = 0;
		ready_set = read_set;
		select(1024, &ready_set, NULL, NULL, &tm);
		if(FD_ISSET(fd_server, &ready_set))
		{
			int fd_client = accept(fd_server, NULL, NULL);
			//find_child_handle()
			for(i = 0; i < atoi(argv[3]); i++)
			{
				if(my_childs[i].s_status == S_IDLE)
				{
					my_childs[i].s_status = S_BUSY;
					FD_SET(my_childs[i].s_read, &read_set);	

					break;
				}
			}

			
		}
		for(i = 0; i < atoi(argv[3]); i++)
		{
			if(FD_ISSET(my_childs[i].s_read, &reay_set))
			{
				//read_from_fd();
				my_childs[i].s_status = S_IDLE;

			}
		}
	}
}
