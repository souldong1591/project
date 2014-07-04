#ifndef __MY_SOCKET__
#define __MY_SoCKET__
#include<stdio.h>
#include "msg.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int listenfd_init(char *ip, char *port);
void handle_request(int fd_client);

#endif
