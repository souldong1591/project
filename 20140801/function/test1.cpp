/*************************************************************************
	> File Name: test1.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月01日 星期五 14时56分42秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <functional>

using namespace std;

void test(int i, double j, const string &s)
{
	cout << "i = " << i << " , j = " << j << " , s = " << s << endl;
}

int main(int argc, const char *argv[])
{
	//1. void(*)(int, double)
	function<void (int, double)> fp;
	string s = "foobar";
	fp = bind(&test, 
			  std::placeholders::_1, 
			  std::placeholders::_2, 
			  s);
	fp(100, 2.34);

	//2. void(*)(double, int, const string &)
	function<void (double, int, const string &)> fp2;
	fp2 = bind(&test, 
			  std::placeholders::_2, 
			  std::placeholders::_1, 
			  std::placeholders::_3);
	fp2(2.34, 100, "foobar");
   
    //3. void (*)(const string &, int)
	function<void (const string &, int)> fp3;
	fp3 = bind(&test,
			   std::placeholders::_2,
			   2.34,
			   std::placeholders::_1);
	fp3("foobar", 100);

    //4. void (*) (const string &, int, double)
    function<void (const string &, int, double)> fp4;
	fp4 = bind(&test,
			   std::placeholders::_2,
			   std::placeholders::_3,
			   std::placeholders::_1);
	fp4("foobar", 100, 2.34);

    //5. void (*)(int)
	function<void (int)> fp5;
	fp5 = bind(&test,
			   std::placeholders::_1,
			   2.34,
			   "foobar");
	fp5(100);

    //6 void(*)(const string &)
	function<void (const string &)> fp6;
	fp6 = bind(&test,
			   100,
			   2.34,
			   std::placeholders::_1);
	fp6("foobar");
    //7. void (*)()
	function<void ()> fp7;
	fp7 = bind(&test,
			   100,
			   2.34,
			   "foobar");
	fp7();
	return 0;
}

