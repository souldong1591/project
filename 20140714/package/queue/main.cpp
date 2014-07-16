/*************************************************************************
	> File Name: main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 15时29分15秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

using namespace std;

int main(int argc, const char *argv[])
{
	Queue q;
	srand(time(NULL));
	cout << "empty: " << q.isEmpty() << endl;
	q.push(rand()%100);
	q.push(rand()%100);
	cout << "empty: " << q.isEmpty() << endl;
	q.push(rand()%100);
	q.push(rand()%100);
	q.push(rand()%100);
	cout << q.top() << endl;
	q.print();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	cout << "empty: " << q.isEmpty() << endl;
	cout << q.top() << endl;
	q.print();
	return 0;
}
