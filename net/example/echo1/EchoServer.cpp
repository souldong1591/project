/*************************************************************************
	> File Name: EchoServer.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 14时58分27秒
 ************************************************************************/

#include "EchoServer.h"
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

EchoServer::EchoServer(const InetAddress &addr)
	:server_(addr)
{
	server_.setConnection(bind(&EchoServer::onConnect, this, _1));
	server_.setMessage(bind(&EchoServer::onMessage, this, _1));
	server_.setClose(bind(&EchoServer::onClose, this, _1));
}

void EchoServer::start()
{
	server_.start();
}

void EchoServer::onConnect(const TcpConnectionPtr &conn)
{
	cout << "client : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " on" << endl;
	conn->send("hello, welcome to Echo Server!\r\n");
}

void EchoServer::onMessage(const TcpConnectionPtr &conn)
{
	string s(conn->receive());
	conn->send(s);
}

void EchoServer::onClose(const TcpConnectionPtr &conn)
{
	cout << "client : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " close" << endl;
	conn->shutdown();
	
}
