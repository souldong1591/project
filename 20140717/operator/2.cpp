/*************************************************************************
	> File Name: 2.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 21时08分47秒
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
		String(const String &other);
		String &operator = (const String &other);
		void debug() const;
		virtual ~String();
	private:
		char *str_;
};

String::String()
	:str_(new char[1])
{
	str_[0] = '\0';	
}

String::String(const char *str)
	:str_(new char[strlen(str) + 1])
{
	strcpy(str_, str);
}

String::String(const String &other)
	:str_(new char[strlen(other.str_) + 1])
{
	strcpy(str_, other.str_);
}

String &String::operator = (const String &other)
{
	if(this != &other)
	{
		delete[] str_;
		str_ = new char[strlen(other.str_) + 1];
		strcpy(str_, other.str_);
		return *this;
	}
}

void String::debug() const
{
	cout << str_ << endl;
}

String::~String()
{
	delete[] str_;
}

int main(int argc, const char *argv[])
{
	String s("hello");
	s = s; 
	s.debug();
	
	return 0;
}
