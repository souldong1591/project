/*************************************************************************
	> File Name: return.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 16时08分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int push()
{
	int num;
	cin >> num;
	if(num == 1)
	{
		return 1;
	}
	else if(num == 2)
	{
		return 2;
	}
	return num;
}


int main(int argc, const char *argv[])
{
	push();
	return 0;
}
