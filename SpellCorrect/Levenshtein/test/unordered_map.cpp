/*************************************************************************
	> File Name: unordered_map.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月11日 星期一 23时11分52秒
 ************************************************************************/


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
int main ()
{
	unordered_map<char, map<string, int> > word_index;
	ifstream is;
	is.open("en.txt");
	string word;
	int num;
	map<string, int> word_count;
	while(is >> word >> num)
	{
		for (int i = 0; i < word.size(); i++)
		{
			word_index.insert(make_pair(word[i], word_count));
			word_index[word[i]][word] = num;
		}
	}
	char c = 'a';
	map<string, int>::const_iterator map_it = word_index[c].begin();
	while(map_it != word_index[c].end())
	{
		cout << map_it->first << endl;
		++map_it;
	}



	return 0;
}
