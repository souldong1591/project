#ifndef RIO_H_
#define RIO_H_ 

#include "NonCopyable.h"
#include <stddef.h>
#include <errno.h>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

#define RIO_BUFFER 8192

class Rio : NonCopyable
{
	public:
		Rio(int fd);
		~Rio();
		
		int rio_read(void *usrbuf, int n);
		int rio_readn(void *usrbuf, int n);
		int rio_writen(int fd, void *usrbuf, int n);
		int rio_readline(void *usrbuf, int n);

	private:
		int fd_;
		int left_;
		char* bufptr_;
		char buffer_[RIO_BUFFER];
};



#endif  /*RIO_H_*/
