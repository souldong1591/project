#ifndef RIO_H_
#define RIO_H_ 

#include "NonCopyable.h"
#include <stddef.h>
#include <stdio.h>
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
		explicit Rio(int fd);
		~Rio();
		
		ssize_t rio_readn(char *usrbuf, size_t n);
		ssize_t rio_writen(const char *usrbuf, size_t n);
		ssize_t rio_readLine(char *usrbuf, size_t n);

	private:
		ssize_t rio_read(char *usrbuf, size_t n);

		int fd_;
		int left_;
		char* bufptr_;
		char buffer_[RIO_BUFFER];
};



#endif  /*RIO_H_*/
