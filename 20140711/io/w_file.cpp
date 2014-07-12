/*************************************************************************
	> File Name: w_file.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 20时07分33秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char *argv[])
{
	if(argc != 2)
	{
		cout << "USAGE: EXE FILE" << endl;
		return -1;
	}
	ofstream os;
	os.open(argv[1]);
	if(!os)
	{
		cerr << "error: " << os << endl;
		return -1;
	}
	string line;
	while(getline(cin, line))
	{
		os << line << endl;
		line.clear();
	}
	

	os.close();
	os.clear();
	return 0;
}
