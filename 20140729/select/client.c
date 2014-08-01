/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月29日 星期二 20时23分34秒
 ************************************************************************/

#include "net.h"
#include <sys/select.h>

void do_client(int peerfd)
{
	char recvbuf[1024] = "";
	char sendbuf[1024] = "";
	
	fd_set readset;
	FD_ZERO(&readset);
	int stdin_fd = fileno(stdin);
	int maxfd = (stdin_fd > peerfd) ? stdin_fd : peerfd;
	int nready;
	while(1)
	{
		FD_ZERO(&readset);
		FD_SET(stdin_fd, &readset);
		FD_SET(peerfd, &readset);
		nready = select(maxfd + 1, &readset, NULL, NULL, NULL);
		if(nready == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("select");
		}
		else if(nready == 0)
			continue;
		
		if(FD_ISSET(stdin_fd, &readset))
		{
			if(fgets(sendbuf, 1024, stdin) == NULL)
			{
				shutdown(peerfd, SHUT_WR);
			}
			else
			writen(peerfd, sendbuf, strlen(sendbuf));
			
		}

		if(FD_ISSET(peerfd, &readset))
		{
			int ret = readline(peerfd, recvbuf, 1024);
			if(ret == -1)
				ERR_EXIT("readline");
			else if(ret == 0)
			{
				printf("server exit\n");
				return ;
			}
			printf("recv data: %s", recvbuf);
		}
	}
}

int main(int argc, const char *argv[])
{
	int peerfd = socket(PF_INET, SOCK_STREAM, 0);
	if(peerfd == -1)
		ERR_EXIT("socket");

	struct sockaddr_in server_addr;
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(8989);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(peerfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
		ERR_EXIT("connect");

	do_client(peerfd);
	close(peerfd);
	return 0;
}
