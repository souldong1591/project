#ifndef __COMPLEX_H__
#define __COMPLEX_H__ 

#include <iostream>
class Complex
{
	friend Complex operator + (const Complex &c1, const Complex &c2);
	friend Complex operator - (const Complex &c1, const Complex &c2);
	friend Complex operator * (const Complex &c1, const Complex &c2);
	friend Complex operator / (const Complex &c1, const Complex &c2);
	friend std::ostream &operator << (std::ostream &os, const Complex &c);
	friend std::istream &operator >> (std::istream &is, const Complex &c);
	public:
		Complex();
		Complex(double real, double imag);
		Complex &operator = (const Complex &c);
		~Complex();
		bool isReal() const;
		double module();
	private:
		double real_;
		double imag_;
};






#endif  /*__COMPLEX_H__*/
