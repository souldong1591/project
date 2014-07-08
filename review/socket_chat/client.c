/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 08 Jul 2014 11:09:16 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct sockaddr_in SA;

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	int fd_server;
	SA server_addr;
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(-1 == connect(fd_server, (struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("connect");
		close(fd_server);
		exit(-1);
	}
	char send_buf[1024] = "";
	while(bzero(send_buf, 1024), fgets(send_buf, 1024, stdin) != NULL)
	{
		send(fd_server, send_buf, strlen(send_buf), 0);
		bzero(send_buf, 1024);
		recv(fd_server, send_buf, 1024, 0);
		printf("recv:%s\n", send_buf);
	}
	close(fd_server);
}
