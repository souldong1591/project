#ifndef SOCKET_H_
#define SOCKET_H_ 

#include "NonCopyable.h"
#include "InetAddress.h"

class Socket : NonCopyable
{
	public:
		explicit Socket(int sockfd);
		~Socket();

		int fd() const;
		void bindAddress(const InetAddress &addr);
		void listen();
		int accept();
		void shutdownWrite();
		void setReusePort();
	private:
		const int sockfd_;
};



#endif  /*SOCKET_H_*/
