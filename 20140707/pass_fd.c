/*************************************************************************
	> File Name: pass_fd.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 07 Jul 2014 10:07:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

void send_fd(int sockfd, int fd_to_send);
void recv_fd(int sockfd, int *fd_to_recv);
void my_handle(int num)
{
	wait();
	exit(0);
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int fds[2];
	socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);
	pid = fork();
	if(pid > 0)
	{
		close(fds[0]);
		signal(17, my_handle);
		int fd_file = open(argv[1], O_RDONLY);
		send_fd(fds[1], fd_file);

	}
	else
	{
		close(fds[1]);
		int fd_file;
		recv_fd(fds[0], &fd_file);
		FILE* fp = fdopen(fd_file, "r");
		char line[1024];
		while(bzero(line, 1024), fgets(line, 1024, fp) != NULL)
		{
			puts(line);
		}
		fclose(fp);

	}
}

void send_fd(int sockfd, int fd_to_send)
{
	struct msghdr send_msg;
	struct cmsghdr* pcmsg;
	int cmsglen = CMSG_LEN(sizeof(int));
	pcmsg = (struct cmsghdr*)calloc(1, cmsglen);
	bzero(&send_msg, sizeof(send_msg));
	send_msg.msg_name = NULL;
	send_msg.msg_namelen = 0;
	send_msg.msg_flags = 0;
	char buf[32] = "hello world !\n";
	struct iovec bufs[1];
	bufs[0].iov_base = buf;
	bufs[0].iov_len = strlen(buf);
	send_msg.msg_iovlen = 1;
	pcmsg->cmsg_len = cmsglen;
	pcmsg->cmsg_level = SOL_SOCKET;
	pcmsg->cmsg_type = SCM_RIGHTS;
	*(int*)CMSG_DATA(pcmsg) = fd_to_send;
	send_msg.msg_control = pcmsg;
	send_msg.msg_controllen = cmsglen;
	sendmsg(sockfd, &send_msg, 0);


}

void recv_fd(int sockfd, int *fd_to_recv)
{
	struct msghdr recv_msg;
	struct cmsghdr *pcmsg;
	int cmsglen = CMSG_LEN(4);
	pcmsg = (struct cmsghdr*)calloc(1, cmsglen);
	struct iovec bufs[1];
	char buf[32] = "";
	bufs[0].iov_base = buf;
	bufs[0].iov_len = strlen(buf);
	recv_msg.msg_iov = bufs;
	recv_msg.msg_iovlen = 1;
	recv_msg.msg_control = pcmsg;
	recv_msg.msg_controllen = cmsglen;
	recvmsg(sockfd, &recv_msg, 0);
	printf("buf: %s \n", buf);
	*fd_to_recv = *(int*)CMSG_DATA(pcmsg);
	

}
