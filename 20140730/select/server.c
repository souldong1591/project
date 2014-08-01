/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 14时58分16秒
 ************************************************************************/

#include "net.h"
#include <sys/select.h>

int get_listen_fd();
void do_select(int peerfd);


int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");

	int listenfd = get_listen_fd();

	do_select(listenfd);

	close(listenfd);
	return 0;
}

int get_listen_fd()
{
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
		ERR_EXIT("socket");
	
	int on = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(8989);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(listenfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
		ERR_EXIT("bind");

	if(listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	return listenfd;
}

void do_select(int listenfd)
{
	fd_set allset, rset;
	int client[FD_SETSIZE];
	memset(client, -1, FD_SETSIZE);
	
	int maxi = -1;
	int nready;
	int maxfd = listenfd;
	FD_ZERO(&rset);
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	
	while(1)
	{
		rset = allset;
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
		if(nready == -1)
		{
			if(errno = EINTR)
				continue;
			ERR_EXIT("select");
		}
		else if(nready == 0)
			continue;
		
		if(FD_ISSET(listenfd, &rset))
		{
			int peerfd = accept(listenfd, NULL, NULL);
			if(peerfd == -1)
				ERR_EXIT("accept");

			int i;
			for (i = 0; i < FD_SETSIZE; i++) 
			{
				if(client[i] == -1)
				{
					client[i] = peerfd;
					if(i > maxi)
						maxi = i;
					break;
				}
			}

			if(i == FD_SETSIZE)
			{
				fprintf(stderr, "to many client\n");
				exit(EXIT_FAILURE);
			}

			FD_SET(peerfd, &allset);
			if(peerfd > maxfd)
				maxfd = peerfd;
			if(--nready <= 0)
				continue;
		}
		
		int i;
		for (i = 0; i <= maxi; i++) 
		{
			if(FD_ISSET(client[i], &rset))
			{
				char recvbuf[1024] = "";
				int fd = client[i];
				int ret = readline(fd, recvbuf, 1024);
				if(ret == -1)
					ERR_EXIT("readline");
				else if(ret == 0)
				{
					printf("client close\n");
					close(fd);
					client[i] = -1;
					FD_CLR(fd, &allset);
					continue;
				}

				printf("recv data: %s", recvbuf);
				writen(fd, recvbuf, strlen(recvbuf));
				if(--nready <= 0)
					break;
			}
		}
		
	}
}
