/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 14时53分31秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NonCopyable
{
	public:
		NonCopyable(){}
		~NonCopyable(){}
	private:
		NonCopyable(const NonCopyable &);
		void operator = (const NonCopyable &);
};

//这里采用私有继承
class Test: private NonCopyable
{};

int main(int argc, const char *argv[])
{
	Test t;
	Test t2(t);
	Test t3;
	t3 = t;
	return 0;
}
