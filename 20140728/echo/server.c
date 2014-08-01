/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月28日 星期一 15时59分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct sockaddr_in SA;

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

void do_server(int peer_fd)
{
	char buf[128] = "";
	int ret;
	while(1)
	{
		bzero(buf, 128);
		ret = read(peer_fd, buf, 128);
		if(ret == -1)
		{
			if(errno == EINTR)
				continue;
			return ;
		}
		else if(ret == 0)
			break;
		else
		{
			write(peer_fd, buf, strlen(buf));
		}
	}
}



int main(int argc, const char *argv[])
{
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
		ERR_EXIT("socket");
	int on = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	SA server_addr;
	bzero(&server_addr, sizeof(SA));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8989);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(SA)) < 0)
		ERR_EXIT("bind");

	if(listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	int peer_fd;
	if((peer_fd = accept(listenfd, NULL, NULL)) < 0)
		ERR_EXIT("accept");

	do_server(peer_fd);
	close(peer_fd);
	close(listenfd);
	return 0;
}
