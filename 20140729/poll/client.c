/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月29日 星期二 15时43分02秒
 ************************************************************************/

#include "net.h"
#include <poll.h>

void do_client(int peerfd)
{
	char recv_buf[1024] = "";
	char send_buf[1024] = "";

	struct pollfd client[2];
	client[0].fd = fileno(stdin);
	client[0].events = POLLIN;
	client[1].fd = peerfd;
	client[1].events = POLLIN;
	int maxi = 1;
	int nready;

	while(1)
	{
		nready = poll(client, maxi + 1, -1);
		if(nready == -1)
		{
			if(errno = EINTR)
				continue;
			ERR_EXIT("poll");
		}
		else if(nready == 0)
			continue;

		if(client[0].events & POLLIN)
		{
			if(fgets(send_buf, 1024, stdin) == NULL)
			{
				shutdown(peerfd, SHUT_WR);
				client[0].fd = -1;
			}
			else
			{
				writen(peerfd, send_buf, strlen(send_buf));

			}
		}

		if(client[1].events & POLLIN)
		{
			int ret = readline(peerfd, recv_buf, 1024);
			if(ret == -1)
				ERR_EXIT("readline");
			else if(ret == 0)
			{
				printf("server close\n");
				close(peerfd);
				break;
			}
			printf("recv data: %s", recv_buf);
		}
	}
}


int main(int argc, const char *argv[])
{
    //创建socket
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("socket");


    //connect
    struct sockaddr_in peeraddr;
    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port = htons(8989);
    peeraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(peerfd, (struct sockaddr *)&peeraddr, sizeof peeraddr) < 0)
        ERR_EXIT("connect");
    


    do_client(peerfd);


    close(peerfd);

    return 0;
}

