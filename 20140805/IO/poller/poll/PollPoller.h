#ifndef POLL_POLLER_H_
#define POLL_POLLER_H_ 

#include <poll.h>
#include "Poller.h"
class PollPoller : Poller
{
	public:
		PollPoller(int listenfd);
		virtual ~PollPoller();
		void do_wait();
		void handle_accept();
		void handle_data();
	private:
		struct pollfd clients_[2048];
		int max_;
		int nready_;
		void add_fd(int fd);
		void del_fd(int i);
				
};




#endif  /*POLL_POLLER_H_*/
