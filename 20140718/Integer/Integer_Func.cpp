/*************************************************************************
	> File Name: Integer_Func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 19时42分33秒
 ************************************************************************/

#include "Integer.h"

Integer::Integer(int data)
	:data_(data)
{}

Integer::~Integer()
{}

std::ostream &operator << (std::ostream &os, const Integer &in)
{
	return os << in.data_;
}

Integer &Integer::operator ++ ()
{
	++data_;
	return *this;
}

Integer Integer::operator ++ (int)
{
	Integer tmp(*this);
	++data_;
	return tmp;
}
