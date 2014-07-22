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
			cout << "Student..." << endl;
		}

};

int main(int argc, const char *argv[])
{
	Student s;
	Student *ps;
	Person *pe;
//	pe = ps;
	pe = &s;
	pe->print();
	ps =(Student *)pe;
	ps->print();


	return 0;
}
