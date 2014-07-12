/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月12日 星期六 11时29分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TEST
{
	public:
		string get_name() const
		{
			return name_;
		}

		void set_name(const string &name) 
		{
			name_ = name;
		}

		int get_score() const
		{
			return score_;
		}

		void set_score(int score)
		{
			score_ = score;
		}
		void print(ostream &os)
		{
			os << "name: " << name_ << "  score: " << score_ << endl;
		}
	private:
		string name_;
		int score_;
};

int main(int argc, const char *argv[])
{
	TEST t;
	t.set_name("zhangsan");
	t.set_score(98);
	t.print(cout);
	return 0;
}
