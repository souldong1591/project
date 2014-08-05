/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月01日 星期五 10时19分25秒
 ************************************************************************/

#include <stdio.h>
#include "Exception.h" 

void foo()
{
	throw Exception("foobar");
}

void bar()
{
	foo();
}

int main(int argc, const char *argv[])
{
	try
	{
		bar();
	}
	catch (Exception& ex)
	{
		printf("reason: %s\n", ex.what());
		printf("stack trace: %s\n", ex.stackTrace());
	}
	return 0;
}
