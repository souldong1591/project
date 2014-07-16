/*************************************************************************
	> File Name: size.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 16时34分55秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
	vector<int> vec;
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;
	vec.reserve(10);
	vec.insert(vec.begin(), 24, 10);
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;
	vec.push_back(10);
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;

	vec.resize(10);
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;

	vec.reserve(50);
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;
	while(vec.size() != vec.capacity())
	{
		vec.push_back(0);
	}
	cout << "size: " << vec.size() << " capacity:" << vec.capacity() << endl;


	return 0;
}
