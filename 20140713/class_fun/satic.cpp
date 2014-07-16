/*************************************************************************
	> File Name: satic.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月13日 星期日 21时49分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account
{
	public:
		Account()
		{
			++sum_;
		}
		virtual ~Account()
		{
			--sum_;
		}
		
		int show_num();

	private:
		static int sum_;
};

int Account::sum_ = 0;

int Account::show_num()
{
	return sum_;
}

int main(int argc, const char *argv[])
{
	Account a, b, c;
	cout << a.show_num() << endl;
	return 0;
}

