/*************************************************************************
	> File Name: my_getsockaopt.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 03 Jul 2014 09:21:34 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
int main()
{
	int sock_fd;
	int recv_size = 0, send_size = 0, reuse = -1;
	int my_send = 8192;
	int my_recv = 8192;
	int len_recv = sizeof(int);
	int len_send = sizeof(int);
	int len_reuse = sizeof(int);
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, &recv_size, &len_recv);
	getsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF, &send_size, &len_send);
	getsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, &len_reuse);
	printf("before:\n");
	printf("socket rcvbuf: %d\nscoket sndbuf: %d\nsocket reuse:%d\n", recv_size, send_size, reuse);
	int iret1 = setsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, &my_recv, sizeof(int));
	int iret2 = setsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF, &my_send, sizeof(int));
	if(iret1 != 0 || iret2 != 0)
	{
		perror("setsockopt");

	}
	else
	{
		getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF, &recv_size, &len_recv);
		getsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF, &send_size, &len_send);
		printf("after:\n");
		printf("socket rcvbuf: %d\nscoket sndbuf: %d\n", recv_size, send_size);
		
	}
}
