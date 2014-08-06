#ifndef EPOLL_POLLER_H_
#define EPOLL_POLLER_H_ 

#include "Poller.h"
#include <sys/epoll.h>

class EpollPoller : Poller
{
	public:
		EpollPoller(int listenfd, const HandleCallback &callback);
		virtual ~EpollPoller();
		
		void do_wait();
		void handle_accept();
		void handle_data(int peerfd);
		void handle();
	private:
		int epollfd_;
		int listenfd_;
		struct epoll_event events_[2048];
		int nready_;
		void add_fd(int fd);
		void del_fd(int fd);
};


#endif  /*EPOLL_POLLER_H_*/
