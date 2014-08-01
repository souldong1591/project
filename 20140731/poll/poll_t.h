#ifndef POLL_T_H_
#define POLL_T_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

typedef struct 
{
	struct pollfd clients_[2048];
	int max_;
	int nready_;
	void (*handle_callback_)(int, char *);
}poll_t;

void poll_init(poll_t *pol, int listenfd);
int poll_do_wait(poll_t *pol);
void poll_handle_accept(poll_t *pol);
void poll_handle_data(poll_t *pol);
void poll_set_callback(poll_t *pol, void (*handle)(int, char*));


#endif  /*POLL_T_H_*/
