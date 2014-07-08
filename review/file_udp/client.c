/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 08 Jul 2014 05:21:00 PM CST
 ************************************************************************/

#include "file_udp.h"

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("USAGE: EXE IP PORT FILE\n");
		exit(-1);
	}

	int fd_client;
	SA server_addr;
	fd_client = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_client == -1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	char buf[128] = "a client on";
	sendto(fd_client, buf, strlen(buf), 0, (struct sockaddr*)&server_addr, sizeof(SA));

	SA from_addr;
	bzero(&from_addr, sizeof(SA));
	int addrlen = sizeof(SA);
	int filelen = 0;
	recvfrom(fd_client, (void*)&filelen, sizeof(int), (struct sockaddr*)&from_addr, &addrlen);

	FILE* fp;
	fp = fopen(argv[3], "wb");
	char file_buf[1024] = "";
	while(1)
	{
		bzero(file_buf, 1024);
		int len = recvfrom(fd_client, file_buf, 1024, 0, (struct sockaddr*)&from_addr, &addrlen);
		if(len < 1024)
		{
			fwrite(file_buf, 1, len, fp);
			break;
		}
		fwrite(file_buf, 1, len, fp);
		
	}
	fclose(fp);

	struct stat my_stat;
	bzero(&my_stat, sizeof(my_stat));
	stat(argv[3], &my_stat);
	int recv_len = my_stat.st_size;
	if(recv_len == filelen)
	{
		printf("OK\n");
	}
	else
	{
		unlink(argv[3]);
	}
	
	close(fd_client);
		

	return 0;
}
