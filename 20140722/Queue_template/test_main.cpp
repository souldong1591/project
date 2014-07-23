/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 20时17分24秒
 ************************************************************************/

#include "Queue.hpp"
#include <iostream>

using namespace std;
int main(int argc, const char *argv[])
{
	Queue<int> q1;
	for (int i = 0; i < 10; i++) 
	{
		q1.push(i);
	}
	
	q1.print();

	q1.pop();
	q1.print();

	Queue<int> q2;
	q2 = q1;
	q2.print();

	Queue<int> q3(q1);
	q3.print();

	return 0;
}
