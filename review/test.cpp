/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月20日 星期日 10时34分47秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Test
{
	public:
		Test():
			a_(0)
		{}

		Test(int a)
		{
			this->a_ = a;
			this->print();
		}

		static void print() const
		{
			cout << a_ << endl;
		}
	private:
		int a_;
};

int main(int argc, const char *argv[])
{
	Test t(10);
	t.print();
	return 0;
}
