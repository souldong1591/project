/*************************************************************************
	> File Name: EchoServer.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 14时58分27秒
 ************************************************************************/

#include "EchoServer.h"
#include "TextQuery.h"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
using namespace std::placeholders;

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

string make_plural(size_t ctr,
				   const string &word, 
				   const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}



EchoServer::EchoServer(const InetAddress &addr)
	:server_(addr),
	 pool_(1000, 4)
{
	server_.setConnection(bind(&EchoServer::onConnect, this, _1));
	server_.setMessage(bind(&EchoServer::onMessage, this, _1));
	server_.setClose(bind(&EchoServer::onClose, this, _1));
}

void EchoServer::start()
{
	pool_.start();
	server_.start();
}

void EchoServer::onConnect(const TcpConnectionPtr &conn)
{
	cout << "client : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " on" << endl;
	conn->send("hello, welcome to Echo Server!\r\nenter word to look for, or q to quit: ");

}

void EchoServer::onMessage(const TcpConnectionPtr &conn)
{
	ifstream infile;
	infile.close();
	infile.clear();
	infile.open("test.txt");
	TextQuery tq;
	tq.read_file(infile);
	string s(conn->receive());
	s.erase(s.size() - 2);
	pool_.addTask(bind(&EchoServer::compute, this, s, conn, tq));
}

void EchoServer::compute(const std::string &word, const TcpConnectionPtr &conn, const TextQuery &tq)
{	
	if(word == "q")
		exit(0);

	typedef set<TextQuery::line_no> line_nums;
	line_nums locs = tq.run_query(word);
	line_nums::size_type size = locs.size();
	
	char ssize[128] = "";
	sprintf(ssize, "%d", size);

	string s;
	s = s + "\n" + word +  " occurs " + ssize + " "
		 + make_plural(size, "time", "s") + "\n";
	line_nums::const_iterator it = locs.begin();
	for ( ; it != locs.end(); ++it)
	{
		char sit[128] = "";
		sprintf(sit, "%d", (*it) + 1);

		s = s +  "\t(line " + sit + ") "
			 + tq.text_line(*it) + "\r\n";
	}
	s = s + "\nenter word to look for, or q to quit: ";
	conn->send(s);
}

void EchoServer::onClose(const TcpConnectionPtr &conn)
{
	cout << "client : " << conn->getPeerAddr().toIp() << " : "
		 << conn->getPeerAddr().toPort() << " close" << endl;
	conn->shutdown();
	
}



