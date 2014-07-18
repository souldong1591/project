#ifndef __STRING_H__
#define __STRING_H__ 

#include <stddef.h>
#include <iostream>
class String
{
	friend String operator + (const String &s1, const String &s2);
	friend String operator + (const String &s1, const char *s2);
	friend String operator + (const char *s1, const String &s2);
	//friend String operator + (const char *s1, const char *s2);

	friend std::ostream &operator << (std::ostream &os, const String &s);
	friend std::istream &operator >> (std::istream &is, String &s);

	friend bool operator < (const String &s1, const String &s2);
	friend bool operator > (const String &s1, const String &s2);
	friend bool operator <= (const String &s1, const String &s2);
	friend bool operator >= (const String &s1, const String &s2);
	friend bool operator == (const String &s1, const String &s2);
	friend bool operator != (const String &s1, const String &s2);

	public:
		String();
		String(const char *str);
		String(const String &s);
		~String();

		String &operator = (const char *str);
		String &operator = (const String &s);

		String &operator += (const char *str);
		String &operator += (const String &s);

		char &operator[](size_t index);
		const char &operator[](size_t index) const;

		size_t size() const;
		const char *c_str() const;

		void debug() const;


		
	private:
		char *str_;	
};




#endif  /*__STRING_H__*/
