/*************************************************************************
	> File Name: my_stu.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Mon 23 Jun 2014 03:29:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct tag
{
	int stu_id;
	char stu_name[20];
}Node, *pNode;

int main(int argc, char *argv[])
{
	int fd_w, i;
	Node stu[5] = {{1, "zhangsan"}, {2, "lisi"}, {3, "wangwu"},
		{4, "qianba"}, {5, "zhaoliu"}};
	fd_w = open("stu.txt", O_WRONLY | O_CREAT, 0666);
	if(fd_w == -1)
	{
		perror("fail:");
		exit(-1);
	}
	
	for(i = 0; i < 5; i++)
	{
		write(fd_w, &stu[i], sizeof(Node));
	}
	close(fd_w);

}
