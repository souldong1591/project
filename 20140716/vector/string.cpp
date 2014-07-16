/*************************************************************************
	> File Name: string.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 16时40分36秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
	string s = "helloworld";
	s.insert(5, 1, ' ');
	cout << s << endl;
	
	return 0;
}
