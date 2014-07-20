/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 19时14分30秒
 ************************************************************************/

#include "SmartPtr.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
	SmartPtr ptr(new Animal);
	(*ptr).run();
	ptr->run();
	return 0;
}
