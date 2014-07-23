/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 17时05分56秒
 ************************************************************************/

#include "SmartPtr.h"
using namespace std;

int main(int argc, const char *argv[])
{
	SmartPtr ptr(new Animal);
	ptr.resetPtr(NULL);
	ptr.resetPtr(new Animal);
	return 0;
}
