/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 21时03分48秒
 ************************************************************************/

#include "net.h"

void do_service(int peerfd)
{
	char recvbuf[1024] = "";
	while(1)
	{
		int ret = readline(peerfd, recvbuf, 1024);
		if(ret == -1)
			ERR_EXIT("readline");
		else if(ret == 0)
		{
			printf("client close\n");
			exit(EXIT_SUCCESS);
		}

		printf("recv data: %s", recvbuf);
		writen(peerfd, recvbuf, strlen(recvbuf));
	}
}

void handler(int signum)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);

	return;
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

int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");
	if(signal(SIGCHLD, handler) == SIG_ERR)
		ERR_EXIT("signal");

	int listenfd = get_listen_fd();
	while(1)
	{
		struct sockaddr_in peer_addr;
		bzero(&peer_addr, sizeof(peer_addr));
		socklen_t len = sizeof(peer_addr);
		int peerfd = accept(listenfd, (struct sockaddr*)&peer_addr, &len);
		if(peerfd == -1)
			ERR_EXIT("accept");
		printf("client on: %d\n", ntohs(peer_addr.sin_port));

		pid_t pid;
		if((pid = fork()) < 0)
			ERR_EXIT("fork");
		else if( pid == 0)
		{
			close(listenfd);
			do_service(peerfd);
			exit(EXIT_SUCCESS);
		}

		close(peerfd);
	}
	close(listenfd);
	return 0;
}
