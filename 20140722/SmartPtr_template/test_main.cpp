/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 17时31分03秒
 ************************************************************************/

#include "SmartPtr.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
class Test
{
	public:
		Test()
		{
			cout << "Test..." << endl;
		}
		~Test()
		{
			cout << "~Test..." << endl;
		}
};

int main(int argc, const char *argv[])
{
	SmartPtr<Test> ptr(new Test);
	SmartPtr<Test> ps;
	assert(ptr);
	cout << ptr.getPtr() << endl;
	ptr.resetPtr(NULL);
	ptr.resetPtr(new Test);
	assert(ptr);
	return 0;
}
