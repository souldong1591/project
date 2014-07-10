/*************************************************************************
	> File Name: vector.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 14时56分14秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	//这里声明了一个int类型的空数组
	//vector不是一种完全的类型， 必须加上类型信息
	vector<int> vec;  
	
	//push_back 是在数组的后面追加元素
	vec.push_back(23);
	vec.push_back(34);
	vec.push_back(67);
	vec.push_back(56);
	vec.push_back(89);
	vec.push_back(31);
	vec.push_back(14);

	cout << "size of vec = " << vec.size() << endl;

	for(vector<int>::size_type ix = 0; ix != vec.size(); ++ix)
	{
		cout << vec[ix] << " ";
	}
	cout << endl;

	vector<string> str;
	
	str.push_back("hello");
	str.push_back("how");
	str.push_back("are");
	str.push_back("world");
	
	cout << "size of str = " << str.size() << endl;
	
	for(vector<string>::size_type ix = 0; ix != str.size(); ++ix)
	{
		cout << str[ix] << " ";
	}
	cout << endl;
	
	str[0] = str[0] + " " + str[3];

	cout << str[0] << endl;
	
	vector<string> words;
	string word;
	while(cin >> word)
	{
		words.push_back(word);
	}
	for(vector<string>::iterator ix = words.begin(); ix != words.end(); ++ix)
	{
		cout << *ix << " ";
	}
	cout << endl;

	


	return 0;
}
