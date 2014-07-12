/*************************************************************************
	> File Name: io3.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 15时56分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
	int num;
	while(cin >> num)
	{
		cout << num <<endl;
	}

	cout << "fail " << cin.fail() << endl;
	cout << "eof " << cin.eof() << endl;

	cin.clear();
	cout << "after clear" << endl;
	cout << "fail " << cin.fail() << endlu55;
	cout << "eof " << cin.eof() << endl;
	
	string s = "HI";
	cin >> s;
	cout << s << endl;
	return 0;
}
