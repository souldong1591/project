/*************************************************************************
	> File Name: 1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 09时24分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
	public:
		/*Student(const string &name, int score)
		{
			name_= name;
			score_ = score;
		}*/

		Student(const string &name, int score):
			name_(name), score_(score){}

		void print() const 
		{
			cout << name_ << " " << score_ << endl;
		}
	private:
		string name_;
		int score_;
};

int main(int argc, const char *argv[])
{
	//Student s("zhangsan", 98);
	Student *s = new Student("lisi", 89);
	(*s).print();
	return 0;
}
