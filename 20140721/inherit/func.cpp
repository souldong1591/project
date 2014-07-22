/*************************************************************************
	> File Name: func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 10时15分36秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
	public:
		Person(){}

		Person(int id,
			   const string &name,
			   int age):
			id_(id),
			name_(name),
			age_(age)
		{}

		void set(int id,
				 const string &name,
				 int age)
		{
			id_ = id;
			name_ = name;
			age_ = age;
		}
		
		void print() const
		{
			cout << "Person " << id_ << " " << name_ << " " << age_ << endl;
		}
	protected:
		int id_;
		string name_;
		int age_;
};

class Student: public Person
{
	private:
		string school_;

	public:
		void set(int id,
				 const string &name,
				 int age,
				 const string &school)
		{
			id_ = id;
			name_ = name;
			age_ = age;
			school_ = school;
		}
		void print() const
		{
			cout << "Student " << id_ << " " << name_ << " " << age_ << " " << school_ << endl;
		}

		
};

int main(int argc, const char *argv[])
{
	Student s1, s2;
	s1.set(12, "zhangsan", 23, "wangdao");
	s1.print();
	s2.Person::set(12, "zhangsan", 23);
	s2.print();
	return 0;
}
