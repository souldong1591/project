#ifndef ECHO_SERVER_H_
#define ECHO_SERVER_H_ 

#include <echo/TcpServer.h>
#include <echo/NonCopyable.h>

class EchoServer : NonCopyable
{
	public:
		EchoServer(const InetAddress &addr);
		void start();
	private:
		void onConnect(const TcpConnectionPtr &conn);
		void onMessage(const TcpConnectionPtr &conn);
		void onClose(const TcpConnectionPtr &conn);

		TcpServer server_;

};


#endif  /*ECHO_SERVER_H_*/
