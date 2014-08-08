#ifndef TCP_CONNECTION_H_
#define TCP_CONNECTION_H_ 

#include "NonCopyable.h"
#include "InetAddress.h"
#include "Socket.h"
#include "Rio.h"
#include <string.h>
#include <memory>
#include <string>

class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class TcpConnection : NonCopyable,
					  public std::enable_shared_from_this<TcpConnection>
{
	public:
		typedef std::function<void (const TcpConnectionPtr &)> TcpConnectionCallback;
		TcpConnection(int sockfd,
				      const InetAddress &localAddr,
					  const InetAddress &peerAddr);
		~TcpConnection();

		int fd() const;
		ssize_t readn(char *usrbuf, size_t n);
		ssize_t readLine(char *usrbuf, size_t maxline);
		ssize_t writen(const char *usrbuf, size_t n);
		void sendString(const std::string &s);
		std::string receiveString();
		void shutdown();

		void setConnectionCallback(const TcpConnectionCallback &cb)
		{ onConnectionCallback_ = cb; }
		void setMessageCallback(const TcpConnectionCallback &cb)
		{ onMessageCallback_ = cb; }
		void setCloseCallback(const TcpConnectionCallback &cb)
		{ onCloseCallback_ = cb; }

		void handleConnection()
		{ 
			if(onConnectionCallback_)
				onConnectionCallback_(shared_from_this()); 
		}

		void handleMessage()
		{ 
			if(onMessageCallback_)
				onMessageCallback_(shared_from_this()); 
		}

		void handleClose()
		{ 
			if(onCloseCallback_)
				onCloseCallback_(shared_from_this()); 
		}

		const InetAddress &getLocalAddr()
		{ return localAddr_; }
		const InetAddress &getPeerAddr()
		{ return peerAddr_; }

	private:
		Socket sockfd_;
		Rio buffer_;

		const InetAddress localAddr_;
		const InetAddress peerAddr_;

		TcpConnectionCallback onConnectionCallback_;
		TcpConnectionCallback onMessageCallback_;
		TcpConnectionCallback onCloseCallback_;


};

#endif  /*TCP_CONNECTION_H_*/
