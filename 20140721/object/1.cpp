/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 14时59分59秒
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
			cout << "Base....." << endl;
		}

		~Base()
		{
			cout << "~Base....." << endl;
		}
};


class Other
{
	public:
		Other()
		{
			cout << "Other...." << endl;
		}
		~Other()
		{
			cout << "~Other...." << endl;
		}
};

class Derived: public Base
{
	public:
		Derived()
		{
			cout << "Derived...." << endl;
		}
		~Derived()
		{
			cout << "~Derived...." << endl;
		}
	private:
		Other other_;
};

int main(int argc, const char *argv[])
{
	Derived d;

	return 0;
}
