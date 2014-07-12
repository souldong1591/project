/*************************************************************************
	> File Name: io.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 15时29分07秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	int num;

	cin >> num;
	cout << num <<endl;

	cout << "bad  " << cin.bad() << endl;
	cout << "fail  " << cin.fail() << endl;
	cout << "eof  " << cin.eof() << endl;
	cout << "good " << cin.good() << endl;
	
	string s = "hello";
	cin >> s;
	cout << s << endl;

	cout << "bad  " << cin.bad() << endl;
	cout << "fail  " << cin.fail() << endl;
	cout << "eof  " << cin.eof() << endl;
	cout << "good " << cin.good() << endl;


	return 0;
}
