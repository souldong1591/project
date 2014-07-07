/*************************************************************************
	> File Name: client.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sun 06 Jul 2014 04:22:17 PM CST
 ************************************************************************/

#include "ftp.h"

void trim_space(char *str);

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	
	//init
	int fd_server, fd_file;
	MSG send_msg, recv_msg, msg;
	SA server_addr;
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == connect(fd_server, (struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("connect");
		close(fd_server);
		exit(-1);
	}
	
	while(bzero(&msg, sizeof(MSG)), fgets(msg.s_buf, sizeof(MSG), stdin) != NULL)
	{
		printf("begin\n");
		if(msg.s_buf[0] == '\n')
		{
			continue;
		}
		trim_space(msg.s_buf);
		msg.s_len = strlen(msg.s_buf);
		send(fd_server, &msg, msg.s_len + MSG_LEN, 0);

		//gets
		if(strncmp(msg.s_buf, "gets", 4) == 0)
		{
			char file_name[256];
			int file_pos = 5;
			while(bzero(file_name, 256), sscanf(msg.s_buf + file_pos, "%s", file_name) == 1)
			{
				file_pos += strlen(file_name) + 1;
				fd_file = open(file_name, O_WRONLY | O_CREAT, 0666);
				while(1)
				{
					bzero(&recv_msg, sizeof(MSG));
					recv(fd_server, &recv_msg, MSG_LEN, 0);
					if(recv_msg.s_len > 0)
					{
						recv(fd_server, recv_msg.s_buf, recv_msg.s_len, 0);
						write(fd_file, recv_msg.s_buf, recv_msg.s_len);
					}
					else
					{
						printf("file >> [%s] download done!\n", msg.s_buf + 5);
						break;
					}
				}
				close(fd_file);
			}
		}
		//puts
		else if(strncmp(msg.s_buf, "puts", 4) == 0)
		{
			char file_name[256];
			int file_pos = 5;
			while(bzero(file_name, 256), sscanf(msg.s_buf + file_pos, "%s", file_name) == 1)
			{
				file_pos += strlen(file_name) + 1;
				fd_file = open(file_name, O_RDONLY);
				while(bzero(&send_msg, sizeof(MSG)), (send_msg.s_len = read(fd_file, send_msg.s_buf, MSG_SIZE)) > 0)
				{
					send(fd_server, &send_msg, send_msg.s_len + MSG_LEN, 0);
				}
				send_msg.s_len = 0;
				send(fd_server, &send_msg, send_msg.s_len + MSG_LEN, 0);
				printf("file >> [%s] upload done!\n", msg.s_buf + 5);
				close(fd_file);
			}
		}    
		//ls   cd  remove wrong
		else 
		{
			system("clear");
			while(1)
			{
				bzero(&recv_msg, sizeof(MSG));
				recv(fd_server, &recv_msg, MSG_LEN, 0);
				if(recv_msg.s_len > 0)
				{
					recv(fd_server, recv_msg.s_buf, recv_msg.s_len, 0);
					printf("%s\n", recv_msg.s_buf);
				}
				else
				{
					break;
				}
			}
			
		}
	
	}
	msg.s_len = 0;
	send(fd_server, &send_msg, send_msg.s_len + MSG_LEN, 0);
	return 0;
	

}

void trim_space(char *str)
{
	int i, j;
	for(i = -1, j = 0; j < strlen(str); j++)
	{
		if(str[j] != ' ')
		{
			str[++i] = str[j];
		}
		else
		{
			if(i != -1 && str[i] != ' ')
			{
				str[++i] = ' ';
			}
		}
	}
	while(i >= 0)
	{
		if(str[i] != ' ')
		{
			break;
		}
		i--;
	}
	if(str[i] == '\n')
	{
		str[i] = '\0';
	}
	else
	{
		str[++i] = '\0';
	}
}

