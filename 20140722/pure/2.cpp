/*************************************************************************
	> File Name: 2.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 10时21分50秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
	public:
		virtual void run() = 0;
		virtual ~Animal() {}
};

class Cat: public Animal
{
	public:
		void run()
		{
			cout << "Cat.." << endl;
		}
};



int main(int argc, const char *argv[])
{
	Animal *pt = new Cat;
	pt->run();
	delete pt;
	return 0;
}
