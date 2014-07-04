/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 04 Jul 2014 09:40:51 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	int fd_server;
	char buf[1024];
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in server_addr, client_addr;
	int addrlen = sizeof(client_addr);
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	while(1)
	{
		bzero(buf, 1024);
		fgets(buf, 1024, stdin);
		sendto(fd_server, buf, strlen(buf), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
		recvfrom(fd_server, buf, 1024, 0, (struct sockaddr*)&server_addr, &addrlen);
		printf("ip:%s port:%d msg:%s\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port), buf);

	}
	return 0;

}
