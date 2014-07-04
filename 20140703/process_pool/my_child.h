#ifndef __MY_CHILD__
#define __MY_CHILD__
#include "my_socket.h"
#define S_BUSY 1
#define S_IDLE 0
typedef struct tag
{
	pid_t s_pid;
	int s_status;
	int s_read;
	int s_write;
	int s_cnt;
}Child, *pChild;

void make_child(pChild arr, int cnt);
void child_main();
#endif
