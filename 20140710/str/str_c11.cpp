/*************************************************************************
	> File Name: str_c11.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 16时39分21秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	vector<string> str;
	
	str.push_back("hello");
	str.push_back("world");
	str.push_back("how");
	str.push_back("are");
	str.push_back("you");
	str.push_back("beijing");

	for(const auto &s: str)
	{
		cout << s << " " ;
	}
	cout << endl;

	return 0;
}
