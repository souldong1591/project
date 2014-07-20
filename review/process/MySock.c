/*************************************************************************
	> File Name: MySock.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月20日 星期日 09时23分36秒
 ************************************************************************/

#include "MySock.h"

int listenfd_init(char *ip, char *port)
{
	int fd_server;
	struct sockaddr_in server_addr, client_addr;
	int reuse = 1;
	if(-1 == (fd_server = socket(AF_INET, SOCK_STREAM, 0)))
	{
		perror("socket");
		exit(-1);
	}
	if(0 != setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)))
	{
		perror("setsockopt");
		close(fd_server);
		exit(-1);
	}
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = 

}
