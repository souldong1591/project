/*************************************************************************
	> File Name: count_if.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月19日 星期六 10时58分06秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
bool great_10(int value)
{
	return value > 10;
}
*/

class GT
{
	public:
		GT(int value):
			value_(value)
		{}

		bool operator () (int value)
		{
			return value > value_;
		}
	private:
		int value_;
};

int main(int argc, const char *argv[])
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(8);
	vec.push_back(21);
	vec.push_back(16);
	vec.push_back(7);
	vec.push_back(22);
	vec.push_back(11);
	
	cout << "vec = ( " ;
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";	
	}		
	cout << " )" << endl;

	int count = count_if(vec.begin(), vec.end(), GT(10));
	cout << "great 10 num : " << count << endl;


	return 0;
}
