/*************************************************************************
	> File Name: stu_vector.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 15时43分38秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct _STU 
{
	string name_;
	int grade_;
};

int main(int argc, const char *argv[])
{
	vector<_STU> s1, s2;
	_STU tmp;
	string name;
	int grade;
	while(cin >> name >> grade)
	{
		tmp.name_ = name;
		tmp.grade_ = grade;
		s1.push_back(tmp);
	}
	for(vector<_STU>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		if((*it).grade_ >= 60)
		{
			s2.push_back(*it);
		}
	}

	cout << endl << "> 60" <<endl;
	for(vector<_STU>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		cout << (*it).name_ << " " << (*it).grade_ << endl;
	}
	
	


	return 0;
}
