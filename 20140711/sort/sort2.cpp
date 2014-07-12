/*************************************************************************
	> File Name: sort2.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月11日 星期五 20时19分09秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu
{
	string name_;
	int score_;
	bool operator< (const Stu other) const{
		if(score_ != other.score_)
		{
			return score_ < other.score_;
		}
		if(name_ != other.name_)
		{
			return name_ < other.name_;
		}
	}
};




int main(int argc, const char *argv[])
{
	Stu s[4] = {
				{"lisi", 78},
				{"zhangsan", 67},
				{"liming", 78},
				{"wangwu", 45}
		       };
	std::sort(s, s + 4);

	for(int i = 0; i != 4; i++)
	{
		cout << s[i].name_ << " " << s[i].score_ << endl; 
	}
	return 0;
}
