/*************************************************************************
	> File Name: cpfile.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 16时42分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

int main(int argc, const char *argv[])
{
	if(argc != 3)
	{
		throw std::runtime_error("USAGE: EXE FILE1 FILE2");
	}

	ifstream is;
	ofstream os;
	is.open(argv[1]);
	if(!is)
	{
		cerr << "error: " << is << endl;
		return -1;
	}
	os.open(argv[2]);
	if(!os)
	{
		cerr << "error: " << os << endl;
		return -1;
	}
	
	string line;
	while(getline(is, line))
	{
		os << line << endl;
		line.clear();
	}
	
	is.close();
	os.close();
	is.clear();
	is.clear();

	return 0;
}
