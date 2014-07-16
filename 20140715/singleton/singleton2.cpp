/*************************************************************************
	> File Name: singleton.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月15日 星期二 21时30分35秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;

class Singleton
{
	public:
		static Singleton *getInstance()
		{
			if(pInstance_ == NULL)
			{
				sleep(1);
				pInstance_ = new Singleton;
			}
			return pInstance_;
		}
	private:
		Singleton(){}
		static Singleton *pInstance_;
};

Singleton *Singleton::pInstance_ = NULL;

void *threadFunc(void *arg)
{
	Singleton *ps = Singleton::getInstance();
	cout << ps << endl;
	return NULL;
}


int main(int argc, const char *argv[])
{
	vector<pthread_t> vec(10);
	for(vector<pthread_t>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		pthread_create(&*it, NULL, threadFunc, NULL);
	}

	for(vector<pthread_t>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		pthread_join(*it, NULL);
	}

	return 0;
}
