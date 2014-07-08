/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 08 Jul 2014 10:27:32 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct sockaddr_in SA;

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}

	int fd_server, fd_client;
	SA server_addr, client_addr;
	bzero(&server_addr, sizeof(SA));
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(-1 == bind(fd_server, (const struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("bind");
		close(fd_server);
		exit(1);
	}

	if(-1 == listen(fd_server, 5))
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}

	bzero(&client_addr, sizeof(SA));
	int addrlen = sizeof(SA);
	fd_client = accept(fd_server, (struct sockaddr*)&client_addr, &addrlen);
	if(fd_client == -1)
	{
		perror("accept");
		close(fd_server);
		exit(-1);
	}
	printf("client on %d\n", ntohs(client_addr.sin_port));
	char recv_buf[1024] = "";
	int recv_n;
	while(bzero(recv_buf, 1024), (recv_n = recv(fd_client, recv_buf, 1024, 0)) > 0)
	{
		printf("ip_port: %s:%d msg:%s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), recv_buf);
		send(fd_client, recv_buf, recv_n, 0);

	}
	printf("recv_n %d\n", recv_n);
	close(fd_server);
	close(fd_client);
	return 0 ;
}
