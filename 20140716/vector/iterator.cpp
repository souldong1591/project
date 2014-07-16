/*************************************************************************
	> File Name: iterator.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 10时24分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<string> vec;
	vec.push_back("beijing");
	vec.push_back("shanghai");
	vec.push_back("guangzhou");
	vec.push_back("shenzhen");
	
	cout << "order :" << endl;
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;

	cout << "r order :" << endl;
	for(vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;


	return 0;
}
