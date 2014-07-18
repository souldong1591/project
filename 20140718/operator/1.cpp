/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 10时04分24秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Person
{
	friend bool operator < (const Person &p1, const Person &p2);
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

bool operator < (const Person &p1, const Person &p2)
{
	return p1.age_ < p2.age_;
}

int main(int argc, const char *argv[])
{
	vector<Person> vec;
	vec.push_back(Person(1, "zhangsan", 18));
	vec.push_back(Person(2, "lisi", 16));
	vec.push_back(Person(3, "wangwu", 22));
	vec.push_back(Person(4, "suwu", 17));
	vec.push_back(Person(5, "shangguan", 19));

	sort(vec.begin(), vec.end());
	for(vector<Person>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		it->print();	
	}		
	return 0;
}
