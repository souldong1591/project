/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 10时12分26秒
 ************************************************************************/

#include "net.h"
#include <pthread.h>

void do_service(int peerfd);
int get_listen_fd();
void *threadFunc(void *arg);

int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");
	int listenfd = get_listen_fd();

	while(1)
	{
		int peerfd = accept(listenfd, NULL, NULL);
		if(peerfd == -1)
			ERR_EXIT("accept");

		int *pfd = (int *)malloc(sizeof(int));
		*pfd = peerfd;
		pthread_t tid;
		if(pthread_create(&tid, NULL, threadFunc, pfd))
			free(pfd);


	}
	close(listenfd);
	return 0;
}

void *threadFunc(void *arg)
{
	int *pfd = (int *)arg;
	int peerfd = *pfd;
	free(pfd);

	pthread_detach(pthread_self());

	do_service(peerfd);
	close(peerfd);
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

void do_service(int peerfd)
{
	char recvbuf[1024] = "";
	int ret;
	while(1)
	{
		int ret = readline(peerfd, recvbuf, 1024);
		if(ret == -1)
			ERR_EXIT("readline");
		else if(ret == 0)
		{
			close(peerfd);
			exit(EXIT_SUCCESS);
		}
		printf("recv data: %s", recvbuf);
		writen(peerfd, recvbuf, strlen(recvbuf));
	}

}
