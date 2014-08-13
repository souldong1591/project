/*************************************************************************
	> File Name: WordIndex.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月12日 星期二 16时35分58秒
 ************************************************************************/

#include "WordIndex.h"
#include <fstream>
#include <string>

using namespace std;

#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

WordIndex::WordIndex(char *path)
	:path_(path)
{}

void WordIndex::creatIndex()
{
	ifstream is;
	is.open(path_);
	if(!is)
		ERR_EXIT("open");

	string word;
	int num;
	map<string, int> word_count;
	while(is >> word >> num)
	{
		for (int i = 0; i < word.size(); i++)
		{
			wordIndex_.insert(make_pair(word[i], word_count));
			wordIndex_[word[i]][word] = num;
		}
	}
	
}
std::unordered_map<char, std::map<string, int> > WordIndex::getIndex() const
{
	return wordIndex_;
}
	
