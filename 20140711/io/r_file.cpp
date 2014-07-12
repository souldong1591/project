/*************************************************************************
	> File Name: r_file.cpp
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
	ifstream is;
	is.open(argv[1]);
	if(!is)
	{
		cerr << "error: " << is << endl;
		return -1;
	}
	string line;
	string word;
	vector<string> vec;
	istringstream iss;
	while(getline(is, line))
	{
		cout << line << endl;
		iss.str(line);
		while(iss >> word)
		{
			
			vec.push_back(word);
		}
		iss.clear();
	}
	
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << endl;	
	}

	is.close();
	is.clear();
	return 0;
}
