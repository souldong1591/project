/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 20时56分24秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
	public:
		Student();
		virtual ~Student();
		void set(const string &name, int age, int score);
		void print() const;
	private:
		Student(const Student &other);
		Student &operator = (const Student &other);
		string name_;
		int age_;
		int score_;
};

Student::Student()
	:name_(""),
	 age_(0), 
	 score_(0)
{}

Student::~Student()
{}


void Student::set(const string &name, int age, int score)
{
	name_ = name;
	age_ = age;
	score_ = score;
}

void Student::print() const
{
	cout << name_ << " " << age_ << " " << score_ << endl;
}

int main(int argc, const char *argv[])
{
	Student s;
	s.set("zhangsan", 18, 98);
	Student s2;
	s2 = s;
	s2.print();
	return 0;
}

