/*************************************************************************
	> File Name: swap.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 10时25分37秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*void swap1(int &a, int &b)
{
	int tmp(a);
	a = b;
	b = tmp;
}*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, const char *argv[])
{
	int i(10);
	int j(5);
	cout << "before i = " << i << " j = " << j << endl;
	swap(i, j);
	cout << "after i = " << i << " j = " << j << endl;

	return 0;
}
