/*************************************************************************
	> File Name: Levenshtein.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月11日 星期一 09时36分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int edit(string s1, string s2)
{
	int max1 = s1.size();
	int max2 = s2.size();

	int **ptr = new int*[max1 + 1];
	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i] = new int[max2 + 1];
	}

	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i][0] = i;
	}

	for (int i = 0; i < max2 + 1; i++)
	{
		ptr[0][i] = i;
	}

	for (int i = 1; i < max1 + 1; i++)
	{
		for (int j = 1; j < max2 + 1; j++)
		{
			int d;
			int tmp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if(s1[i - 1] == s2[j - 1])
				d = 0;
			else
				d = 1;
			ptr[i][j] = min(tmp, ptr[i - 1][j - 1] + d);
		}
	}

	int dis = ptr[max1][max2];
	for (int i = 0; i < max1 + 1; i++)
	{
		delete[] ptr[i];
		ptr[i] = NULL;
	}
	delete[] ptr;
	ptr = NULL;

	return dis;
}


struct word_tmp
{
	pair<string, int> word_;
	int dis_;
	bool operator < (const word_tmp &other) const
	{
		if(dis_ == other.dis_)
			return word_.second < other.word_.second;
		else
			return dis_ > other.dis_;
	}
};


void spell(map<string, int> &word_count, const string &s)
{
	int dis = 0;
	map<string, int>::const_iterator map_it = word_count.begin();

	priority_queue<word_tmp> queue_word;
	while(map_it != word_count.end())
	{
		if(fabs((map_it->first.size() - s.size()) / s.size()) > 0.3)
		{
			++map_it;
			continue;
		}
		dis = edit(s, map_it->first);
		if(dis <= s.size() / 2)
		{
		word_tmp w1 = {*map_it, dis};
		queue_word.push(w1);
		cout << "return : " << map_it->first << "  " << map_it->second << "  dis :" << dis << endl;
		}
		++map_it;
	}

	cout << "----------------------------------------" << endl;
	if(!queue_word.empty())
		cout << "return : " << queue_word.top().word_.first << "  " << queue_word.top().word_.second << endl;


}


int main(int argc, const char *argv[])
{
	if(argc != 2)
		throw runtime_error("USAGE : EXE FILE");
	
	string s;
	ifstream is;
	is.open(argv[1]);
	if(!is)
		ERR_EXIT("open");

	map<string, int> word_count;
	string word;
	int num;
	while(is >> word >> num)
		word_count[word] = num;
	while(cin >> s)
	{
		spell(word_count, s);
	}
	return 0;
}
