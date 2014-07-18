/*************************************************************************
	> File Name: String_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 14时22分22秒
 ************************************************************************/

#include "String.h"
#include <string.h>
#include <iostream>
using namespace std;
String::String()
	:str_(new char[1])
{
	str_[0] = '\0';
}


String::String(const char *str)
	:str_(new char[::strlen(str) + 1])
{
	::strcpy(str_, str);
}

String::String(const String &s)
	:str_(new char[s.size() + 1])
{
	::strcpy(str_, s.str_);
}

String::~String()
{
	delete str_;
}

String &String::operator = (const char *str)
{
	if(str_ != str)
	{
		delete str_;
		str_ = new char[::strlen(str) + 1];
		::strcpy(str_, str);
	}
	return *this;
}

String &String::operator = (const String &s)
{
	if(this != &s)
	{
		delete str_;
		str_ = new char[s.size() + 1];
		::strcpy(str_, s.str_);
	}
	return *this;
}

String &String::operator += (const char *str)
{
	return operator += (String(str));
}

String &String::operator += (const String &s)
{
	char *pt = new char[size() + s.size() + 1];
	::strcpy(pt, str_);
	::strcat(pt, s.str_);
	delete str_;
	str_ = pt;
	return *this;
}

char &String::operator [] (size_t index)
{
	return str_[index];
}

const char &String::operator [] (size_t index) const
{
	return str_[index];
}

size_t String::size() const
{
	return ::strlen(str_);
}

const char *String::c_str() const
{
	return str_;
}

void String::debug() const
{
	cout << str_ << endl;
}

String operator + (const String &s1, const String &s2)
{
	String ret(s1);
	ret += s2;
	return ret;
}

String operator + (const String &s1, const char *s2)
{
	return s1 + String(s2);
}

String operator + (const char *s1, const String &s2)
{
	return String(s1) + s2;
}


std::ostream &operator << (std::ostream &os, const String &s)
{
	return os << s.str_;
}

std::istream &operator >> (std::istream &is, String &s)
{
	char buf[1024];
	is >> buf;
	if(is)
	{
		s = buf;
	}
	return is;
}


bool operator < (const String &s1, const String &s2)
{
	return ::strcmp(s1.str_, s2.str_) < 0; 
}

bool operator > (const String &s1, const String &s2)
{
	return s2 < s1;
}

bool operator <= (const String &s1, const String &s2)
{
	return !(s1 > s2);
}

bool operator >= (const String &s1, const String &s2)
{
	return !(s1 < s2);
}
bool operator == (const String &s1, const String &s2)
{
	return ::strcmp(s1.str_, s2.str_) == 0;
}

bool operator != (const String &s1, const String &s2)
{
	return !(s1 == s2);
}

