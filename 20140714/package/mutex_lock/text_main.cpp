/*************************************************************************
	> File Name: text_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 19时39分33秒
 ************************************************************************/

#include "mutex_lock.h"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
	
	Mutex_lock lock;
	lock.lock();
	cout << "lock1" << endl;
	lock.unlock();
	return 0;
}
