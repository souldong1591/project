/*************************************************************************
	> File Name: ConsumeThread.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 21时33分23秒
 ************************************************************************/

#include "ConsumeThread.h"
#include "Buffer.h"
#include <unistd.h>

ConsumeThread::ConsumeThread(Buffer &buffer):
	buffer_(buffer)
{}

void ConsumeThread::run()
{
	while(1)
	{
		buffer_.consume();
		sleep(1);
	}
}
