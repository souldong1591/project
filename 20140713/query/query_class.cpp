/*************************************************************************
  > File Name: query_class.cpp
  > Author: Soul
  > Mail:souldong1591@gmail.com 
  > Created Time: 2014年07月13日 星期日 15时05分52秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

ifstream &open_file(ifstream &in, const string &name)
{
	in.close();
	in.clear();
	in.open(name.c_str());
	return in;
}


class QUERY
{
	public:
		void readFile(const string &name);

		vector<string> queryword(const string &word);


	private:
		vector<string> words_;
};

void QUERY::readFile(const string &name)
{
	ifstream is;
	if(!open_file(is, name))
	{
		throw runtime_error("open");
	}
	words_.clear();
	string word;
	while(is >> word)
	{
		words_.push_back(word);
	}
	is.close();
	is.clear();

}

vector<string> QUERY::queryword(const string &word)
{
	vector<string> result;
	for(vector<string>::iterator it = words_.begin(); it != words_.end(); ++it)
	{
		string::size_type pos = it->find(word);
		if(pos != string::npos)
		{
			result.push_back(*it);
		}
	}
	return result;
}


int main(int argc, const char *argv[])
{
	string filename = argv[1];
	QUERY Q;
	Q.readFile(filename);
	string word;
	while(cin >> word)
	{
		vector<string> res = Q.queryword(word);
		cout << "total: " << res.size() << endl;
		for(vector<string>::iterator it = res.begin(); it != res.end(); ++it)
		{
			cout << *it << " ";	
		}
		cout << endl;
	}
	return 0;
}


