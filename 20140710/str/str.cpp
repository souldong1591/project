/*************************************************************************
	> File Name: str.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 09时49分59秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	string s1, s2;
	cin >> s1;
	cout << s1 << endl;
	cin >> s2;
	cout << s2 << endl;

	bool rt;
	rt = (s1 > s2);
	cout << rt << endl;

	s1 += "world";
	cout << s1 << endl;

	cout << s1.size() << endl;
	
	for(string::size_type i(0); i != s1.size(); i++)
	{
		cout << s1[i] << " " ;
		
	}
	cout << endl;
	
	for(string::iterator i = s1.begin(); i != s1.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
	
	for(auto &s: s1)
	{
		cout<< s <<endl;
	}


	return 0;
}
