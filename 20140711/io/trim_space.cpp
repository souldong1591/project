/*************************************************************************
	> File Name: trim_space.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 23时40分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

void trim_space(string &h)
{
	unsigned int n = 0;
	unsigned int i = 0;
	unsigned int j = 0;

	while ((n = h.find_first_of(' ', 0)) != string::npos && n == 0)
	{
		h.erase(n, 1);
	}

	while ((n = h.find_last_of(' ', h.size() - 1)) != string::npos && n == h.size() - 1)
	{
		h.erase(n, 1);
	}

	while ((n = h.find_first_of(' ', i)) != string::npos) 
	{
		j = n + 1;
		while (h.find_first_of(' ', j) == j )
		{
			h.erase(j, 1);
		}
		i = j;
	}

}

int main(int argc, const char *argv[])
{
	if(argc != 2)
	{
		cout << "USAGE: EXE FILE" << endl;
		return -1;
	}

	ifstream is;
	is.open(argv[1]);
	string line;
	while(getline(is, line))
	{
		trim_space(line);
		cout << line << endl;
	}
	return 0;
}
