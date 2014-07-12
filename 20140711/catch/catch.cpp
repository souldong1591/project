/*************************************************************************
  > File Name: catch.cpp
  > Author: Soul
  > Mail:souldong1591@gmail.com 
  > Created Time: 2014年07月11日 星期五 00时06分57秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main(int argc, const char *argv[])
{

	try{
		int num;
		cin >> num;
		if(num == 1)
		{
			throw runtime_error("1");
		}
		else if(num == 2)
		{
			throw out_of_range("2"); 
		}
		else if(num == 3)
		{
			throw logic_error("3");
		}

	}
	catch(runtime_error &e)
	{
		cout << "runtime" <<endl;
	}
	catch(...)
	{
		cout << "catch a exc" << endl;
	}

	cout << "over" << endl;
	return 0;
}
