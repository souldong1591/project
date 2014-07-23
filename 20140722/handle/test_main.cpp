/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 14时46分11秒
 ************************************************************************/

#include "Animal.h"
#include "Handle.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<Handle> vec;
	Dog d1;
	Cat c1, c2;
	Beer b1, b2, b3;
	vec.push_back(b1);
	vec.push_back(b2);
	vec.push_back(b3);
	vec.push_back(c1);
	vec.push_back(c2);
	vec.push_back(d1);

	for(vector<Handle>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		(*it)->display();	
	}

	cout << endl;
	Dog d;
	Handle h(d);
	h->display();



	return 0;
}
