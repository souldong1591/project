/*************************************************************************
	> File Name: server.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Sun 06 Jul 2014 10:02:57 AM CST
 ************************************************************************/

#include "ftp.h"

void sig_handle(int num)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[])
{
	//deal signal
	signal(13, SIG_IGN);
	signal(17, sig_handle);
	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT\n");
		exit(-1);
	}
	
	int fd_server, fd_client, reuse = 1;
	SA server_addr, client_addr;
	bzero(&server_addr, sizeof(SA));
	fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}   

	//ip address reset
	if(0 != setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)))
	{
		perror("setsockopt");
		close(fd_server);
		exit(-1);
	}

	//tcp init
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == bind(fd_server, (struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}
	if(-1 == listen(fd_server, 5))
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}

	int addrlen = sizeof(SA);
	while(bzero(&client_addr, sizeof(SA)), (fd_client = accept(fd_server, (struct sockaddr*)&client_addr, &addrlen)) > 0)
	{
		if(fd_client == -1)
		{
			if(errno == EINTR)
			{
				continue;
			}
		}
		printf("ip_port: %s:%d connect\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		//child process
		if(fork() == 0)
		{
			close(fd_server);
			MSG msg, send_msg, recv_msg;
			int fd_file;
			while(1)
			{
				bzero(&msg, sizeof(MSG));
				recv(fd_client, &msg, MSG_LEN, 0);
				if(msg.s_len > 0)
				{
					recv(fd_client, msg.s_buf, msg.s_len, 0);

					//gets
					if(strncmp(msg.s_buf, "gets", 4) == 0)
					{
						char file_name[256];
						int file_pos = 5;
						while(bzero(file_name, 256), sscanf(msg.s_buf + file_pos, "%s", file_name) == 1)
						{
							file_pos += strlen(file_name) + 1;
							fd_file = open(file_name, O_RDONLY);
							while(bzero(&send_msg, sizeof(MSG)), (send_msg.s_len = read(fd_file, send_msg.s_buf, MSG_SIZE)) > 0)
							{
								send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
							}
							send_msg.s_len = 0;
							send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
							close(fd_file);
						}
					}    
					// puts
					else if(strncmp(msg.s_buf, "puts", 4) == 0)
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
								recv(fd_client, &recv_msg, MSG_LEN, 0);
								if(recv_msg.s_len > 0)
								{
									recv(fd_client, recv_msg.s_buf, recv_msg.s_len, 0);
									write(fd_file, recv_msg.s_buf, recv_msg.s_len);
								}
								else
								{
									break;
								}
						}
						close(fd_file);
						}
					}
					//ls
					else if(strncmp(msg.s_buf, "ls", 2) == 0)
					{
						DIR *pDir;
						char str[5];
						struct dirent *myent;
						struct stat mystat;
						pDir = opendir(".");
						bzero(&mystat, sizeof(mystat));
						stat(".", &mystat);
						while((myent = readdir(pDir)) != NULL)
						{
							bzero(&send_msg, sizeof(MSG));
							bzero(str, 5);
							stat(myent->d_name, &mystat);
							if(S_ISDIR(mystat.st_mode))
							{
								strcpy(str, "no");
							}
							else
							{
								strcpy(str, "yes");
							}
							if(strncmp(myent->d_name, ".", 1) != 0)
							{
								sprintf(send_msg.s_buf, "name: %-10s download: %-5s size: %d", myent->d_name, str, myent->d_reclen);
								send_msg.s_len = strlen(send_msg.s_buf);
								send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
							}
						}
						bzero(&send_msg, sizeof(MSG));
						send_msg.s_len = 0;
						send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
					}
					//cd
					else if(strncmp(msg.s_buf, "cd", 2) == 0)
					{
						if(chdir(msg.s_buf + 3) == 0)
						{
							bzero(&send_msg, sizeof(MSG));
							getcwd(send_msg.s_buf, MSG_SIZE);
							send_msg.s_len = strlen(send_msg.s_buf);
							send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);

						}
						else
						{
							bzero(&send_msg, sizeof(MSG));
							strcpy(send_msg.s_buf, "cd: No such file or directory");
							send_msg.s_len = strlen(send_msg.s_buf);
							send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
						}

						bzero(&send_msg, sizeof(MSG));
						send_msg.s_len = 0;
						send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);

					}
					//remove
					else if(strncmp(msg.s_buf, "remove", 6) == 0)
					{
						if(unlink(msg.s_buf + 7) == 0)
						{
							bzero(&send_msg, sizeof(MSG));
							strcpy(send_msg.s_buf, msg.s_buf + 7);
							strcat(send_msg.s_buf, " remove sucess!");
							send_msg.s_len = strlen(send_msg.s_buf);
							send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);

						}
						else
						{
							bzero(&send_msg, sizeof(MSG));
							strcpy(send_msg.s_buf, "No such file or directory");
							send_msg.s_len = strlen(send_msg.s_buf);
							send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
						}
						bzero(&send_msg, sizeof(MSG));
						send_msg.s_len = 0;
						send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);


					}
					//wrong
					else
					{
						bzero(&send_msg, sizeof(MSG));
						strcpy(send_msg.s_buf, "command not found");
						send_msg.s_len = strlen(send_msg.s_buf);
						send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);
						bzero(&send_msg, sizeof(MSG));
						send_msg.s_len = 0;
						send(fd_client, &send_msg, send_msg.s_len + MSG_LEN, 0);

					}
				}
				else
				{
					break;
				}
			}
			printf("ip_port: %s:%d off\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
			exit(0);
		}

	}


}


