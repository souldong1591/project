/*************************************************************************
	> File Name: main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月08日 星期五 15时55分06秒
 ************************************************************************/

#include "TextQuery.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

string make_plural(size_t ctr,
				   const string &word, 
				   const string &ending);

ifstream &open_file(ifstream &in, const string &file);

void print_results(const set<TextQuery::line_no> &locs,
		           const string &sought,
				   const TextQuery &file);


int main(int argc, const char *argv[])
{
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]))
	{
		cerr << "No input file !" << endl;
		return EXIT_FAILURE;
	}

	TextQuery tq;
	tq.read_file(infile);
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if(!cin || s == "q")
			break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}

string make_plural(size_t ctr,
				   const string &word, 
				   const string &ending)
{
	return (ctr == 1) ? word : word + ending;
	//make_plural(wc, "word ", "s ")当输入中文本中
	//word数大于一是在word后加s，为words为word的复数！
}

ifstream &open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

void print_results(const set<TextQuery::line_no> &locs,
		           const string &sought,
				   const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs " << size << " "
		 << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it = locs.begin();
	for ( ; it != locs.end(); ++it)
		cout << "\t(line " << (*it) + 1 << ") "
			 << file.text_line(*it) << endl;
}
