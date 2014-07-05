/*************************************************************************
  > File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Fri 04 Jul 2014 07:37:55 PM CST
 ************************************************************************/

#include "chat.h"
#include <pthread.h>
void *recv_func(void *arg)
{
	int fd_client = (int)arg;
	char buf[1024];
	SA from_addr;
	MSG msg;
	int addrlen = sizeof(from_addr);
	while(1)
	{
		bzero(buf, 1024);
		bzero(&from_addr, sizeof(SA));
		bzero(&msg, sizeof(MSG));

		recvfrom(fd_client, &msg, sizeof(MSG), 0, (struct sockaddr*)&from_addr, &addrlen);
		printf("ip %s:%d msg:%s\n", inet_ntoa(msg.s_addr.sin_addr), ntohs(msg.s_addr.sin_port), msg.s_msg);
	}
}
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}

	int fd_client;
	fd_client  = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_client == -1)
	{
		perror("socket");
		close(fd_client);
		exit(-1);
	}
	SA server_addr;
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	MSG msg_on, msg_off, msg_chat;
	bzero(&msg_on, sizeof(MSG));
	msg_on.s_type = MSG_ON;
	sendto(fd_client, &msg_on, sizeof(MSG), 0,(struct sockaddr*)&server_addr, sizeof(SA));
	pthread_t pthid;
	pthread_create(&pthid, NULL, recv_func, (void*)fd_client);
	int choice;
	char chat_ip_port[32];
	int ip_port[5];
	while(fflush(stdin), printf("usr(1) or grp(2): "), scanf("%d", &choice) != EOF)
	{
		if(choice != 1 && choice != 2)
		{
			printf("wrong choice\n");
			continue;
		}
		if(choice == 1)
		{
			while(printf("Talk ip port:"), fflush(stdout), bzero(chat_ip_port, 32), fgets(chat_ip_port, 32, stdin) != NULL)
			{
				if(chat_ip_port[0] == '\n')
				{
					continue;
				}
				else
				{
					if(5 != sscanf(chat_ip_port, "%d.%d.%d.%d %d", &ip_port[0], &ip_port[1], &ip_port[2], &ip_port[3], &ip_port[4]))
					{
						continue;
					}
					else if(ip_port[0] > 255 || ip_port[1] > 255 || ip_port[2] > 255 || ip_port[3] > 255)
					{
						continue;
					}
					printf("Now you can speak!\n");
					while(bzero(&msg_chat, sizeof(MSG)),fgets(msg_chat.s_msg, MSG_SIZE, stdin) != NULL)
					{
						msg_chat.s_type = MSG_USR;
						msg_chat.s_len = strlen(msg_chat.s_msg);
						msg_chat.s_addr.sin_family = AF_INET;
						msg_chat.s_addr.sin_port = htons(ip_port[4]);
						bzero(chat_ip_port, 32);
						sprintf(chat_ip_port, "%d.%d.%d.%d", ip_port[0], ip_port[1], ip_port[2], ip_port[3]);
						msg_chat.s_addr.sin_addr.s_addr = inet_addr(chat_ip_port);
						sendto(fd_client, &msg_chat, sizeof(MSG), 0, (struct sockaddr*)&server_addr, sizeof(SA));

					}
					

				}


			}
		}
		else if(choice == 2)
		{
			printf("Now you can speak!\n");
			while(bzero(&msg_chat, sizeof(MSG)),fgets(msg_chat.s_msg, MSG_SIZE, stdin) != NULL)
			{
				msg_chat.s_type = MSG_GRP;
				msg_chat.s_len = strlen(msg_chat.s_msg);
				sendto(fd_client, &msg_chat, sizeof(MSG), 0, (struct sockaddr*)&server_addr, sizeof(SA));

			}
			
		}
	}
	bzero(&msg_off, sizeof(MSG));
	msg_off.s_type = MSG_OFF;
	sendto(fd_client, &msg_off, sizeof(MSG), 0,(struct sockaddr*)&server_addr, sizeof(SA));
	close(fd_client);
	return 0;
}

