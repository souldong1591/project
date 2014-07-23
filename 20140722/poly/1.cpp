/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 10时10分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
	public:
		virtual void print() const
		{
			cout << "Base......" << endl;
		}

};

class Derived: public Base
{
	public:
		void print() const
		{
			cout << "Derived......" << endl;
		}
};


int main(int argc, const char *argv[])
{
	Base *pt = new Derived;
	pt->print();

	cout << "sizeof Base " << sizeof(Base) << endl;
	cout << "sizeof Derived " << sizeof(Derived) << endl; 
	return 0;
}
