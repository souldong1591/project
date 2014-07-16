/*************************************************************************
	> File Name: append.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 17时11分33秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	string s = "helloworld";
	cout << s.substr(5, 3) << endl;
	
	s.append("hello");
	cout << s << endl;

	s.append("hello", 3);
	cout << s << endl;

	s.append(string("world"));
	cout << s << endl;

	s.append(string("foobar"), 3, 3);
	cout << s << endl;

	s.append(8, 's');
	cout << s << endl;

	string tmp = "zhangsan";
	string::iterator it1 = find(tmp.begin(), tmp.end(), 'h'),
		it2 = find(tmp.begin(), tmp.end(), 'g');
	s.append(it1, it2);
	cout << s << endl;
	return 0;
}
