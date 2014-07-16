/*************************************************************************
	> File Name: ij.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月13日 星期日 21时12分59秒
 ************************************************************************/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class X
{
	public:
		X(int val):
			j(val),i(j){}
		void print()
		{
			cout << i << " " << j << endl;
		}
	private:
		int i;
		int j;
};

int main(int argc, const char *argv[])
{
	X x(3);
	x.print();
	return 0;
}
