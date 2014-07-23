/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 10时33分09秒
 ************************************************************************/

#include "thread.h"
#include <iostream>
#include <unistd.h>
using namespace std;
class Test: public Thread
{
	public:
		void run()
		{
			while(1)
			{
				sleep(1);
				cout << "hello" << endl;
			}
		}
};

int main(int argc, const char *argv[])
{
	Test t;
	t.start();
	t.join();

	return 0;
}
