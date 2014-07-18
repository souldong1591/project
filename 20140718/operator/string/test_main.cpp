/*************************************************************************
	> File Name: test_main.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 15时34分47秒
 ************************************************************************/

#include "String.h"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
	String s1;
	s1 = "hello";
	s1 += "world";
	cout << s1 << endl;
	String s2(s1);
	cout << s2 << endl;
	cout << (s1 == s2) << endl;
	String s3;
	s3 = s1 + s2 + "how";
	cout << s3 << endl;
	String s4;
	cin >> s4;
	cout << s4 << endl;
	return 0;
}
