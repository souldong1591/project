/*************************************************************************
	> File Name: fun1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 10时58分32秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void push(vector<int> &vec, int num)
{
	vec.push_back(num);
}

int main(int argc, const char *argv[])
{
	vector<int> vec;
	push(vec, 3);
	cout << vec[0] << endl;
	return 0;
}
