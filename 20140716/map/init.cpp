/*************************************************************************
	> File Name: init.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月16日 星期三 20时31分38秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;

class Student
{
	public:

	private:
		int num_;
		string name_;
};

int main(int argc, const char *argv[])
{
	std::map<int, int> m1;
	std::map<string, int> m2;
	map<string, string> m3;

	map<string, vector<string> > m4;

	map<list<vector<list<string> > >, stack<queue<int> > > m5;

	map<int, Student> m6;
	map<Student, int> m7;
	return 0;
}
