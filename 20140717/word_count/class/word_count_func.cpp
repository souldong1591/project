/*************************************************************************
	> File Name: word_count_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 20时01分35秒
 ************************************************************************/

#include "word_count.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
WordCount::WordCount(const string &file_name)
	:file_name_(file_name)
{
	readExclude();
}

void WordCount::readExclude()
{
	ifstream is;
	is.open(file_name_.c_str());
	if(!is)
	{
		throw runtime_error("open file failed");
	}
	string word;
	while(is >> word)
	{
		exclude_.insert(word);
	}
	is.close();
}

WordCount::~WordCount()
{}

void WordCount::add(const string &word)
{
	if(!exclude_.count(word))
	{
		++words_[word];
	}
}

void WordCount::print() const
{
	for(map<string, int>::const_iterator it = words_.begin(); it != words_.end(); ++it)
	{
		cout << it->first << ": " << it->second << endl;	
	}
}
