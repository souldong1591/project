#ifndef __INTEGER_H__
#define __INTEGER_H__ 

#include <iostream>
class Integer
{
	friend std::ostream &operator << (std::ostream &os, const Integer &in);

	public:
		Integer(int data);
		~Integer();
		Integer &operator ++ ();
		Integer operator ++ (int);
	private:
		int data_;
};


#endif  /*__INTEGER_H__*/
