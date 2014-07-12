/*************************************************************************
	> File Name: cal.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 17时04分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string &add(const string &s1, const string &s2)
{
	return s1;
}

int add(const int a, const int b)
{
	return a + b;
}


int main(int argc, const char *argv[])
{
	cout << add(2, 3) << endl;

	cout << add("hello ", "world") << endl;

	return 0;
}
