/*************************************************************************
	> File Name: Complex_Func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 20时21分50秒
 ************************************************************************/

#include "Complex.h"
#include <math.h>
#include <iostream>
Complex::Complex()
	:real_(0), imag_(0)
{}  

Complex::Complex(double real, double imag)
	:real_(real), imag_(imag)
{}

Complex &Complex::operator = (const Complex &c)
{
	if(this != &c)
	{
		real_ = c.real_;
		imag_ = c.imag_;
	}
	return *this;
}

Complex::~Complex()
{}

bool Complex::isReal() const
{
	return imag_ == 0;
}

double Complex::module()
{
	return ::sqrt(real_ * real_ + imag_ * imag_);
}

Complex operator + (const Complex &c1, const Complex &c2)
{
	Complex tmp;
	tmp.real_ = c1.real_ + c2.real_;
	tmp.imag_ = c1.imag_ + c2.imag_;
	return tmp;
}


Complex operator - (const Complex &c1, const Complex &c2)
{
	Complex tmp;
	tmp.real_ = c1.real_ - c2.real_;
	tmp.imag_ = c1.imag_ - c2.imag_;
	return tmp;
		
}

Complex operator * (const Complex &c1, const Complex &c2)
{
	Complex tmp;
	tmp.real_ = c1.real_ * c2.real_ - c1.imag_ * c2.imag_;
	tmp.imag_ = c1.imag_ * c2.real_ + c1.real_ * c2.imag_;
	return tmp;
	
}

Complex operator / (const Complex &c1, const Complex &c2)
{
	Complex tmp;
	double low = c2.real_ * c2.real_ + c2.imag_ * c2.imag_;
	tmp.real_ = (c1.real_ * c2.real_ + c1.imag_ * c2.imag_) / low;
	tmp.imag_ = (c1.imag_ * c2.real_ - c1.real_ * c2.imag_) / low;
	return tmp;
	
}

std::ostream &operator << (std::ostream &os, const Complex &c)
{
	return os << c.real_ << " + " << c.imag_ << "i";
}

std::istream &operator >> (std::istream &is, Complex &c)
{
	double real, imag;
	is >> real;
	if(is)
	{
		is >> imag;
		if(is)
		{
			c = Complex(real, imag);
		}
	}
	return is;
}
