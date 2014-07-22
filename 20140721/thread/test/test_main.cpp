/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 19时49分49秒
 ************************************************************************/

#include "thread.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class Test: public Thread
{
	public:
		Test():
			count_(1)
		{}
		
		void run()
		{
			while(1)
			{
				sleep(1);
				cout << "test" << count_++ << endl;
			}
		}
	private:
		int count_;
};



int main(int argc, const char *argv[])
{
	Test t;
	t.start();
	t.join();
	return 0;
}
