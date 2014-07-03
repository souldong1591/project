/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 02 Jul 2014 04:37:41 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define IP "192.168.1.68"
#define PORT 8888
int main()
{
	int fd_server;
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
	if(connect(fd_server, (const struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		close(fd_server);
		exit(-1);
	}
	
	char send_buf[128] = "";
	while(memset(send_buf, 0, 128), fgets(send_buf, 128, stdin) != NULL)
	{
		int send_n = send(fd_server, send_buf, strlen(send_buf), 0);
		char recv_buf[128] = "";
		int recv_n = recv(fd_server, recv_buf, 128, 0);
		printf("recv from IP:%s:%d\nMsg:%s\nlen:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port), recv_buf, recv_n);
	}




}

