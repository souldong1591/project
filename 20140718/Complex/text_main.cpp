/*************************************************************************
	> File Name: text_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 21时39分56秒
 ************************************************************************/

#include "Complex.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	Complex c1(1, 2);
	Complex c2(2, 4);
	Complex c3;
	c3 = c1 + c2;
	cout << c3 << endl;




	return 0;
}
