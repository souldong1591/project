/*************************************************************************
	> File Name: 01simple.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 14时39分30秒
 ************************************************************************/

#include <echo/TcpServer.h>
#include <iostream>
using namespace std;

void onConnect(const TcpConnectionPtr &conn)
{
	cout << "cilent : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " on" << endl;
	conn->send("hello\r\n");
}

void onMessage(const TcpConnectionPtr &conn)
{
	string s(conn->receive());
	conn->send("ACK\r\n");
}

void onClose(const TcpConnectionPtr &conn)
{
	cout << "cilent : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " close" << endl;
}

int main(int argc, const char *argv[])
{
	TcpServer server(InetAddress(8989));
	server.setConnection(&onConnect);
	server.setMessage(&onMessage);
	server.setClose(&onClose);
	server.start();
	return 0;
}
