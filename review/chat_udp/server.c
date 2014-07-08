/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 08 Jul 2014 03:25:16 PM CST
 ************************************************************************/

#include "chat_udp.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	
	int fd_server;
	SA server_addr;
	fd_server = socket(AF_INET, DGRAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(-1 == bind(fd_server, (struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}

	 while(1)
	 {
		
	 }


	return 0;
}
