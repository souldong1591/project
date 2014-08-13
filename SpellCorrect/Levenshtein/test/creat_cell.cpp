/*************************************************************************
	> File Name: creat_cell.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月11日 星期一 15时37分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
void creat_cell(ifstream &is, ofstream &os)
{
	string word;
	while(is >> word)
	{
		os << word << " " << rand()%1000 << endl;
	}

}





int main(int argc, const char *argv[])
{
	srand(time(NULL));
	ifstream is;
	is.open(argv[1]);
	ofstream os;
	os.open(argv[2]);
	creat_cell(is, os);
	return 0;
}
