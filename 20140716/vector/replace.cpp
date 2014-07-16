/*************************************************************************
	> File Name: replace.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 17时27分43秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{
	string s = "helloworld";
	s.replace(4, 3, "test");
	cout << s << endl;

	s.replace(4, 3, string("foobar"), 3, 3);
	cout << s << endl;
	return 0;
}
