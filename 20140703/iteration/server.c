/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 03 Jul 2014 10:02:19 AM CST
 ************************************************************************/

#include<stdio.h>
#include "my_socket.h"
int main(int argc , char* argv[])//exe ip port
{
	signal(13,SIG_IGN);
	if(argc != 3)
	{
		printf("usge : exe ip port");
		exit(-1);
	}
	int fd_server,fd_client;
	struct sockaddr_in client_addr ;
	int addrlen = sizeof(client_addr);
	fd_server = listenfd_init(argv[1], argv[2]);

	while(fd_client = accept(fd_server,(struct sockaddr*)&client_addr,&addrlen))
	{
		printf("a client connect :%s:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		handle_request(fd_client);
	
	}

}
