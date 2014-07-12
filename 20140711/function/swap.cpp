/*************************************************************************
	> File Name: swap.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 11时06分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#define de_swap(a, b){\
	int tmp = a;\
	a = b;\
	b = tmp;\
} 



using namespace std;

/*
void my_swap(int* &a, int* &b)
{
	int* tmp(a);
	a = b;
	b = tmp;
}
*/

/*
template <typename T>
void my_swap (T *a, T *b)
{
	T tmp(*a);
	*a = *b;
	*b = tmp;
}
*/

template <typename T>
void my_swap (T &a, T &b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

inline void in_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(int argc, const char *argv[])
{
	int a = 1;
	int b = 2;
	string s1 = "hello";
	string s2 = "world";

	cout << "before a = " << a << "  b = " << b << endl;
	my_swap(a, b);
	cout << "after a = " << a << "  b = " << b << endl;
	
	cout << "before s1 = " << s1 << "  s2 = " << s2 << endl;
	my_swap(s1, s2);
	cout << "after s1 = " << s1 << "  s2 = " << s2 << endl;
	
	int i = 3;
	int j = 4;
	cout << "before i = " << i << "  j = " << j << endl;
	in_swap(&i, &j);
	cout << "after i = " << i << "  j = " << j << endl;

	i = 3;
	j = 4;
	cout << "before i = " << i << "  j = " << j << endl;
	de_swap(i, j);
	cout << "after i = " << i << "  j = " << j << endl;
	

	return 0;
}
