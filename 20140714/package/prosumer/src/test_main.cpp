/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 15时29分26秒
 ************************************************************************/

#include "factory.h"
using namespace std;

int main(int argc, const char *argv[])
{
	Factory fac(5, 2, 1);
	fac.start();
	
	return 0;
}
