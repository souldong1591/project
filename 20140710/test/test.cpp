/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 22时01分24秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char &fun(string &s, string::size_type i)
{
	return s[i];
}

int main(int argc, const char *argv[])
{
	
	string s = "hello";
	fun(s, 2) = 'c';
	cout << s << endl;
	return 0;
}
