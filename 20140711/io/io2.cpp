/*************************************************************************
	> File Name: io2.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 15时43分11秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

int main(int argc, const char *argv[])
{
	int ival;
	using std::cin;
	while (cin >> ival, !cin.eof()) 
	{
		if (cin.bad())
			throw std::runtime_error("IO stream corrupted");
		if (cin.fail()) {
			std::cerr << "bad data, try again!" << std::endl;
			cin.clear(); 
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			continue;
		}
		cout << ival << endl;
	}

	return 0;
}
