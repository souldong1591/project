#ifndef POLLER_H_
#define POLLER_H_ 

#include "NonCopyable.h"
#include <functional>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

class Poller : NonCopyable
{
	public:
		typedef std::function<void (int, char*)> HandleCallback;

		virtual ~Poller()
		{}
		virtual void do_wait() = 0;
		virtual void handle_accept() = 0;
		virtual void handle_data() = 0;
	protected:
		HandleCallback callback_;
		virtual void add_fd(int fd) = 0;
		virtual void del_fd(int i) = 0;
};




#endif  /*POLLER_H_*/
