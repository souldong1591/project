/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 21时43分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>


using namespace std;

int main(int argc, const char *argv[])
{
	string s = "hello\n";
	cout << s;
	s.erase(s.size() - 1);
	cout << s;
	return 0;
}
