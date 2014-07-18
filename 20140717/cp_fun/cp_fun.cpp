/*************************************************************************
	> File Name: cp_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 16时19分40秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Student
{
	public:
		Student()
			:name_(""),
			 age_(0),
			 score_(0)
		{}
		
		Student(const Student &other)
			:name_(other.name_),
			 age_(other.age_),
			 score_(other.score_)
		{}

		virtual ~Student()
		{}

		void set(const string &name, int age, int score)
		{
			name_ = name;
			age_ = age;
			score_ = score;
		}

		void print() const
		{
			cout << name_ << " " << age_ << " " << score_ << endl;
		}


	private:
		string name_;
		int age_;
		int score_;
};

int main(int argc, const char *argv[])
{
	Student s;
	s.set("zhangsan", 12, 99);
	
	Student s2(s);
	s2.print();
	
	return 0;
}
