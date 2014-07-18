/*************************************************************************
	> File Name: word_count.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 09时37分48秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <fstream>
using namespace std;
void print(const map<string, int>::value_type &p)
{
	cout << p.first << " :  " << p.second << " times" << endl;
}
int main(int argc, const char *argv[])
{
	if(argc != 2)
	{
		throw runtime_error("USAGE: EXE FILE");
	}

	ifstream is;
	is.open(argv[1]);
	if(!is)
	{
		throw runtime_error("open failed");
	}

	set<string> s;
	string n_word;
	while(is >> n_word)
	{
		s.insert(n_word);
	}
	is.close();

	map<string, int> word_count;
	string word;

	while(cin >> word)
	{
		if(!s.count(word))
		{
			++word_count[word];
		}
	
	}

	for_each(word_count.begin(), word_count.end(), print);


	return 0;
}
