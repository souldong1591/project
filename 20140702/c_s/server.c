/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 02 Jul 2014 03:54:09 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define IP "127.0.0.1"
#define PORT 8888
int main()
{
	int fd_server, fd_client;
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server == -1)
	{
		perror("scoket");
		exit(-1);
	}
	
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(IP);

	if(bind(fd_server, (const struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}

	if(listen(fd_server, 5) == -1)
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}
	
	struct sockaddr_in client_addr;
	int len = sizeof(client_addr);
	fd_client = accept(fd_server, (struct sockaddr*)&client_addr, &len);
	char recv_buf[128] = "";
	int recv_n;
	while(memset(recv_buf, 0, 128), (recv_n = recv(fd_client, recv_buf, 128, 0)) > 0)
	{
		puts(recv_buf);

		FILE* fp_r;
		fp_r = fopen(recv_buf, "r");
		if(fp_r == NULL)
		{
			perror("open");
			exit(-1);
		}
		char send_buf[1024];
		while(memset(send_buf, 0, 1024), fread(send_buf, 1, 1024, fp_r) > 0)
		{
			send(fd_client, send_buf, strlen(send_buf), 0);
		}
		printf("over\n");
	}
	close(fd_server);
	close(fd_client);
	return 0;
}
