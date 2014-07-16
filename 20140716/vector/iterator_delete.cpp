/*************************************************************************
	> File Name: iterator_delete.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 11时05分28秒
 ************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<string> vec;
	vec.push_back("beijing");
	vec.push_back("shanghai");
	vec.push_back("guangzhou");
	vec.push_back("shenzhen");
	vec.push_back("chengdu");
	
	list<string> lst(vec.begin(), vec.end());

/*	lst.pop_back();
	lst.pop_front();
*/

	list<string>::iterator iter1 = find(lst.begin(), lst.end(), "shanghai");
	lst.erase(iter1);
	
	list<string>::iterator first = find(lst.begin(), lst.end(), "guangzhou"), last = find(lst.begin(), lst.end(), "chengdu");

	lst.erase(first, last);


	for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;

	//lst.clear();
	lst.erase(lst.begin(), lst.end());
	for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "  ";	
	}
	cout << endl;


	return 0;
}
