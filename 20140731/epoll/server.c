/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月30日 星期三 14时58分16秒
 ************************************************************************/

#include "net.h"
#include "epoll_t.h"

int get_listen_fd();

void handler(int fd, char *recvbuf)
{
	printf("recv data: %s", recvbuf);
	writen(fd, recvbuf, strlen(recvbuf));
}

int main(int argc, const char *argv[])
{
	if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		ERR_EXIT("signal");

	int listenfd = get_listen_fd();
	epoll_t epol;
	epoll_init(&epol, listenfd, handler);
	while(1)
	{
		epoll_do_wait(&epol);
		epoll_handle(&epol);
		
	}
	epoll_close(&epol);

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


