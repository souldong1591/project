/*************************************************************************
	> File Name: char_re.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 15时20分58秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	string s;
	while(cin >> s)
	{
		string::iterator it = s.begin();
		while(it != s.end())
		{
			if(*it >= 'A' && *it <= 'Z')
			{
				*it += 32;
			}
			else if(*it >= 'a' && *it <= 'z')
			{
				*it -= 32;	
			}
			++it;
		}

		cout << s <<endl;
	}
	return 0;
}
