/*************************************************************************
	> File Name: sort.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 20时13分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, const char *argv[])
{
	int a[3] = {7, 2, 6};
	std::sort(a, a + 3, cmp);
	for(int i = 0; i != 3; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
