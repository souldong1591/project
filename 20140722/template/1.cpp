/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 16时10分07秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T>
T add(const T &a, const T &b)
{
	return a + b;
}
int main(int argc, const char *argv[])
{
	int a = add(2, 3);
	cout << a << endl;
	return 0;
}
