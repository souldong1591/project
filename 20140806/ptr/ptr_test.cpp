/*************************************************************************
	> File Name: ptr_test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月06日 星期三 10时37分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Test
{
	public:
		Test()
		{
			cout << "Test" << endl;
		}

		~Test()
		{
			cout << "~Test" << endl;
		}
};

int main(int argc, const char *argv[])
{
	shared_ptr<Test> ptr(new Test);
	cout << ptr.use_count() << endl;
	cout << ptr.unique() << endl;

	shared_ptr<Test> ptr2(ptr);
	cout << ptr.use_count() << endl;
	cout << ptr.unique() << endl;
	return 0;
}
