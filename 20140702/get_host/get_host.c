/*************************************************************************
	> File Name: get_host.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: Wed 02 Jul 2014 03:23:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
	struct hostent *my_ent;
	if(argc == 1)
	{
		char buf[128];
		gethostname(buf, 128);
		printf("hostname: %s\n", buf);
		my_ent = gethostbyname(buf);
	}
	else
	{
		my_ent = gethostbyname(argv[1]);
	}

	printf("name:%s\n", my_ent->h_name);
	printf("type:%d\n", my_ent->h_addrtype);
	printf("length:%d\n", my_ent->h_length);
	printf("list:\n");
	char **p = my_ent->h_addr_list;
	for(;*p != NULL; p++)
	{
		printf("%x\n", *(int*)*p);
	}


}
