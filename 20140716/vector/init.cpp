/*************************************************************************
	> File Name: init.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 10时04分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<string> vec;
	vec.push_back("hello");
	vec.push_back("world");

	vector<string> vec2(vec);
	vector<string> vec3(vec.begin(), vec.end());
	vector<string> vec4(10, "test");
	list<string> lst(vec.begin(), vec.end());

	cout << "vec : " << endl;
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;	
	}
	cout << endl;

	cout << "vec2 : " << endl;
	for(vector<string>::iterator it = vec2.begin(); it != vec2.end(); ++it)
	{
		cout << *it << endl;	
	}
	cout << endl;

	cout << "vec3 : " << endl;
	for(vector<string>::iterator it = vec3.begin(); it != vec3.end(); ++it)
	{
		cout << *it << endl;	
	}
	cout << endl;

	cout << "vec4 : " << endl;
	for(vector<string>::iterator it = vec4.begin(); it != vec4.end(); ++it)
	{
		cout << *it << endl;	
	}
	cout << endl;
	
	cout << "list : " << endl;
	for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << endl;	
	}
	cout << endl;

	
	//指针当迭代器
	const size_t MAX_SIZE = 3;
	string arr[MAX_SIZE] = {"how", "are", "you"};
	vector<string> vec5(arr, arr + MAX_SIZE);
	cout << "arr vec" << endl;
	for(vector<string>::iterator it = vec5.begin(); it != vec5.end(); ++it)
	{
		cout << *it << endl;	
	}





	return 0;
}
