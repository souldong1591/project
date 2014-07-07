/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sat 05 Jul 2014 08:40:32 PM CST
 ************************************************************************/

#include "pool_udp.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	int fd_client; 
	char buf[1024];
	fd_client = socket(AF_INET, SOCK_DGRAM, 0);
	SA server_addr;
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	while(bzero(buf, 1024), fgets(buf, 1024, stdin) != NULL)
	{
		SA from_addr;
		bzero(&from_addr, sizeof(SA));
		int addrlen = sizeof(SA);
		
		sendto(fd_client, buf, strlen(buf), 0, (struct sockaddr*)&server_addr, sizeof(SA));
		bzero(buf, 1024);
		recvfrom(fd_client, buf, 1024, 0, (struct sockaddr*)&from_addr, &addrlen);
		write(1, buf, sizeof(buf));	
	}

	
}
