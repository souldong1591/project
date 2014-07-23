/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 10时15分35秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
	public:
		Base()
		{
			cout << "Base..." << endl;
		}
		~Base()
		{
			cout << "~Base..." << endl;
		}
};

class Derived: public Base
{
	public:
		Derived()
		{
			cout << "Derived..." << endl;
		}
		~Derived()
		{
			cout << "~Derived..." << endl;
		}
};

int main(int argc, const char *argv[])
{
	Base *pt = new Derived;

	delete pt;
	return 0;
}
