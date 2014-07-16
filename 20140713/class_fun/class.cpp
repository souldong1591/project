/*************************************************************************
	> File Name: class.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月13日 星期日 20时53分05秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	public:
		Person(const string &name, int score)
		{
			name_ = name;
			score_ = score;
		}
		virtual ~Person(){}
		void print()
		{
			cout << name_ << " " << score_ << endl;
		}
	private:
		string name_;
		int score_;
};

int main(int argc, const char *argv[])
{
	Person p("zhangsan", 98);
	p.print();
	
	return 0;
}
