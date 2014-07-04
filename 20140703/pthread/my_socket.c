/*************************************************************************
	> File Name: my_socket.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Thu 03 Jul 2014 07:00:48 PM CST
 ************************************************************************/

#include "my_socket.h"

int listenfd_init(char *ip, char *port)
{
	int fd_server;
	struct sockaddr_in server_addr,client_addr ;
	int reuse = 1 ;
	if((fd_server = socket(AF_INET,SOCK_STREAM, 0) ) == -1)
	{
		perror("socket");
		exit(-1);
	}
	if(0 != setsockopt(fd_server,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int)))
	{
		perror("setsockopt");
		close(fd_server);
		exit(-1);
	}
	memset(&server_addr, 0 , sizeof(server_addr)) ;
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(port));
	server_addr.sin_addr.s_addr = inet_addr(ip);
	if(-1 == bind(fd_server,(struct sockaddr*)&server_addr,sizeof(server_addr)))
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}
	if(-1 == listen(fd_server,5))
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}
	return fd_server;
}

void handle_request(int fd_client)
{
	int fd_file;
	int read_n ;
	int sum=0;
	MSG msg,snd_msg ;
	
	memset(&msg,0, sizeof(msg));
	recv(fd_client,&msg, MSG_LEN , 0) ;
	recv(fd_client,msg.s_buf,msg.s_len,0) ;
	printf("recv msg :%s \n", msg.s_buf);
	fd_file = open(msg.s_buf,O_RDONLY);
	while(memset(&snd_msg,0,sizeof(msg)), (read_n = read(fd_file,snd_msg.s_buf,MSG_SIZE)) > 0)
	{
		snd_msg.s_len = read_n ;
		send(fd_client, &snd_msg, snd_msg.s_len + MSG_LEN ,0);
		sum += snd_msg.s_len;
	}
	snd_msg.s_len = 0 ;
	printf("sum :%d\n", sum);
	send(fd_client, &snd_msg, snd_msg.s_len + MSG_LEN ,0);
	close(fd_file);
	close(fd_client);
}
