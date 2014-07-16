/*************************************************************************
	> File Name: iterator_add.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 10时32分24秒
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
	
	list <string> lst;
	lst.push_front("test");
	lst.push_back("foo");
	lst.insert(++lst.begin(), vec.begin(), vec.end());
	

	cout << "vec :" << endl;
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;

	cout << "list :" << endl;
	for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;
	return 0;
}
