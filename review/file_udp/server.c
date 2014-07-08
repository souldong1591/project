/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Tue 08 Jul 2014 04:37:42 PM CST
 ************************************************************************/

#include "file_udp.h"

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("USAGE: EXE IP PORT FILE\n");
		exit(-1);
	}
	
	int fd_server;
	SA server_addr;
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
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
	
	SA from_addr;
	bzero(&from_addr, sizeof(SA));
	int addrlen = sizeof(SA);
	char buf[128] = "";
	recvfrom(fd_server, buf, 128, 0, (struct sockaddr*)&from_addr, &addrlen);
	printf("%s , port:%d\n", buf, ntohs(from_addr.sin_port));

	FILE* fp;
	fp = fopen(argv[3], "rb");
	struct stat my_stat;
	bzero(&my_stat, sizeof(my_stat));
	stat(argv[3], &my_stat);
	int filelen = my_stat.st_size;
	
	sendto(fd_server, (void*)&filelen, sizeof(int), 0, (struct sockaddr*)&from_addr, sizeof(SA));
	
	char file_buf[1024];
	while(bzero(file_buf, 1024), !feof(fp))
	{
		int len = fread(file_buf, 1, 1024, fp);
		sendto(fd_server, file_buf, len, 0, (struct sockaddr*)&from_addr, sizeof(SA));

	}
	fclose(fp);
	close(fd_server);


	return 0;
}
