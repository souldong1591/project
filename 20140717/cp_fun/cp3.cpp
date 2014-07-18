/*************************************************************************
	> File Name: cp2.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 20时40分20秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class String
{
	public:
		String();
		String(const char *str);
		String(const String &s);
		virtual ~String();
		void debug() const;
	private:
		char *str_;
};

String::String(const char *str)
	:str_(new char[strlen(str) + 1])
{
	strcpy(str_, str);
}

String::String(const String &s)
	:str_(new char[strlen(s.str_) + 1])
{
	strcpy(str_, s.str_);
}

String::~String()
{
	delete[] str_;
}

void String::debug() const
{
	cout << str_ << endl;
}

int main(int argc, const char *argv[])
{
	String s("hello");
	s.debug();

	String s2(s);
	s2.debug();

	return 0;
}
