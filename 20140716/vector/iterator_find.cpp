/*************************************************************************
	> File Name: iterator_find.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 11时23分00秒
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
	vec.push_back("hangzhou");
	vec.push_back("chengdu");

	std::string query;
	while(cin >> query)
	{
		vector<string>::iterator iter = std::find(vec.begin(), vec.end(), query);
		if(iter == vec.end())
		{
			cout << "not found!" << endl;
		}
		else
		{
			cout << "->" << *iter << endl;
		}
	}

	return 0;
}
