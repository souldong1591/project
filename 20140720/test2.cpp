/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月20日 星期日 23时03分21秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person()
			:id_(-1), name_(""), age_(0)
		{

		};
		Person(int id, const string &name, int age)
			:id_(id), name_(name), age_(age)
		{

		}
		void print()
		{
			cout << "id=" << id_ << " name=" << name_ << " age=" << age_ <<endl;	
		}
	private:
		int id_;
		string name_;
		int age_;
};

class Student: public Person
{
	private:
		string school_;
	public:
		void test()
		{
			name_ = "test";
		}
};

class Worker: public Person
{
	private:
	string factory_;	
};

int main(int argc, const char *argv[])
{
	Student s;
	s.print();
	return 0;
}
