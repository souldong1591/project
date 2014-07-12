/*************************************************************************
	> File Name: int.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 22时50分06秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;;
int main(int argc, const char *argv[])
{
	int *p1 = new int;
	int *p2 = new int();
	cout << *p1 << *p2 << endl;

	return 0;
}
