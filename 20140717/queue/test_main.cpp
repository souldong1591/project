/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 23时08分30秒
 ************************************************************************/

#include "queue.h"
#include <iostream>

using namespace std;
int main(int argc, const char *argv[])
{
	Queue q1;
	for (int i = 0; i < 10; i++) 
	{
		q1.push(i);
	}
	
	q1.print();

	q1.pop();
	q1.print();

	Queue q2;
	q2 = q1;
	q2.print();

	Queue q3(q1);
	q3.print();




	return 0;
}
