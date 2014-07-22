/*************************************************************************
  > File Name: 1.cpp
  > Author: Soul
  > Mail:souldong1591@gmail.com 
  > Created Time: 2014年07月21日 星期一 14时36分52秒
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
				int age)
			:id_(id),
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
			cout << "Person..." << endl;
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
		Student(){}
		Student(int id,
				const string name,
				int age,
				const string &school)
			:Person(id, name, age), school_(school)
		{}
		

		void print() const
		{
			cout << "Student..." << endl;
		}

};

int main(int argc, const char *argv[])
{
	Student s;
	Person *ptr;
	ptr = &s;
	ptr->print();
	return 0;
}
