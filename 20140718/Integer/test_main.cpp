/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 19时47分23秒
 ************************************************************************/

#include "Integer.h"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
	Integer a(10);
	cout << a << endl;
	cout << ++a << endl;
	cout << a++ << endl;
	return 0;
}
