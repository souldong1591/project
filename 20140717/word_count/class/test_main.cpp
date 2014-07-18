/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 20时19分26秒
 ************************************************************************/

#include "word_count.h"
#include <iostream>
#include <stdexcept>

using namespace std;
int main(int argc, const char *argv[])
{
	if(argc != 2)
	{
		throw runtime_error("USAGE: EXE FILE");
	}
	
	WordCount w(argv[1]);

	string word;
	while(cin >> word)
	{
		w.add(word);
	}
	w.print();
	

	return 0;
}
