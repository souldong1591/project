#ifndef SELECT_POLLER_H_
#define SELECT_POLLER_H_ 

#include <functional>
#include <sys/select.h>
#include "Poller.h"

class SelectPoller : Poller
{
	public:
		SelectPoller(int listenfd, const HandleCallback &callback);
		~SelectPoller();

		void do_wait();
		void handle_accept();
		void handle_data();

	private:
		int listenfd_;
		fd_set allset_;
		fd_set rset_;
		int client_[FD_SETSIZE];
		int maxi_;
		int maxfd_;
		int nready_;
		void add_fd(int fd);
		void del_fd(int i);
};



#endif  /*SELECT_H_*/
