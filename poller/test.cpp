/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月06日 星期三 15时21分05秒
 ************************************************************************/

#include "TcpConnection.h"
#include "PollPoller.h"
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

//int get_listen_fd();

void onConnect(const TcpConnectionPtr &conn)
{
	cout << "client on " << conn->getPeerAddr().toIp() << " : " 
		 << conn->getPeerAddr().toPort() << endl;
	conn->sendString("hello\n");
	
}

void onMessage(const TcpConnectionPtr &conn)
{
	conn->receiveString();
	conn->sendString("ACK\r\n");
	/*
	string s(conn->receiveString());
	cout << "recv data: " << s;
	conn->sendString(s);
	*/
}

void onClose(const TcpConnectionPtr &conn)
{
	cout << "close conn" << endl;
	conn->shutdown();
}

int main(int argc, const char *argv[])
{
	int fd = ::socket(PF_INET, SOCK_STREAM, 0);
	if(fd == -1)
		ERR_EXIT("socket");
	Socket sock(fd);
	InetAddress addr(8989);
	sock.setReusePort();
	sock.bindAddress(addr);
	sock.listen();

	PollPoller poller(sock.fd());
//	poller.setConnectionCallback(onConnect);
	poller.setMessageCallback(onMessage);
//  poller.setCloseCallback(onClose);
	while(1)
	{
		poller.poll();
		poller.handleAccept();
		poller.handleData();
	}
    
    return 0;
}

/*
int get_listen_fd()
{
    //创建socket
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");


    //设置端口复用
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //bind端口
    if(::bind(listenfd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0)
        ERR_EXIT("bind"); 

    //listen端口
    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    return listenfd;
}
*/

