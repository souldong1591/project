/*************************************************************************
	> File Name: ptr1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 09时19分18秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
	public:
		void setValue(const string &name, int score)
		{
			name_ = name;
			score_ = score;
		}
		
		static void draw()
		{
			cout << "draw" << endl;
		}

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
	void(Student::*func)(const string &, int) = &Student::setValue;
	Student t;
	(t.*func)("lisi", 99);
	t.print();
	return 0;
}
