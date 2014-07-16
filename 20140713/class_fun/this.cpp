/*************************************************************************
	> File Name: this.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月13日 星期日 21时21分28秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person
{
	public:
		Person():
			name_("none"), score_(-1){}
		Person(const string &name, int score):
			name_(name), score_(score){}

		Person &set_name(const string &name)
		{
			name_ = name;
			return *this;
		}

		Person &set_score(int score)
		{
			score_ = score;
			return *this;
		}
		
		Person &print(ostream &os)
		{
			os << name_ << " " << score_ << endl;
			return *this;
		}
		const Person &print(ostream &os) const
		{
			os << name_ << " " << score_ << endl;
		}
		virtual ~Person() {}
	private:
		string name_;
		int score_;
};

int main(int argc, const char *argv[])
{
	Person p;
	p.print(cout);
	p.set_name("zhangsan").print(cout).set_score(98).print(cout);
	return 0;
}
