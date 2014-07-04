#ifndef __MSG__
#define __MSG__
#define MSG_SIZE 8188
#define MSG_LEN (8192 - MSG_SIZE)
typedef struct tag
{
	int s_len;
	char s_buf[MSG_SIZE];
}MSG;

#endif
