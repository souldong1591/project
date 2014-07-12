/*************************************************************************
	> File Name: io4.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 16时30分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	int num;
	cout << "good " << cin.good() << endl;
	cout << (bool)cin << endl;
	cin >> num;
	cout << "good " << cin.good() << endl;
	cout << (bool)cin << endl;

	return 0;
}
