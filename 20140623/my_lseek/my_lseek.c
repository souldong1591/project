/*************************************************************************
	> File Name: my_lseek.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 03:29:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
typedef struct tag
{
	int stu_id;
	char stu_name[20];
}Node, *pNode;

int main(int argc, char *argv[])
{
	int fd_rw, read_n, i;
	Node t;
	fd_rw = open("stu.txt", O_RDWR);
	if(fd_rw == -1)
	{
		perror("fail:");
		exit(-1);
	}
	memset(&t, 0, sizeof(Node));
	lseek(fd_rw, 3*sizeof(Node), SEEK_CUR);
	read(fd_rw, &t, sizeof(Node));
	strcpy(t.stu_name, "xiugai");
	lseek(fd_rw, -sizeof(Node), SEEK_CUR);
	write(fd_rw, &t, sizeof(Node));
	lseek(fd_rw, 0, SEEK_SET);
	while(memset(&t, 0, sizeof(Node)), (read_n = read(fd_rw, &t, sizeof(Node))) > 0)
	{
		printf("stu_id:%d  stu_name:%s\n", t.stu_id, t.stu_name);
	}
	
	close(fd_rw);

}
