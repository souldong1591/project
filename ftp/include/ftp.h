#ifndef __FTP__
#define __FTP__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <pwd.h>
#define MSG_SIZE 8188
#define MSG_LEN (8192 - MSG_SIZE)

typedef struct sockaddr_in SA;
typedef struct tag
{
	int s_len;
	char s_buf[MSG_SIZE];
}MSG;


#endif
