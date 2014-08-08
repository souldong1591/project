/*************************************************************************
	> File Name: main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 15时11分09秒
 ************************************************************************/

#include "EchoServer.h"
using namespace std;

int main(int argc, const char *argv[])
{
	EchoServer server(InetAddress(8989));
	server.start();
	return 0;
}
