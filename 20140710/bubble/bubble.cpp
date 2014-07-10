/*************************************************************************
	> File Name: bubble.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 16时58分33秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubble_sort(vector<int>&vec, bool (*cmp) (int , int))
{
	size_t up = 0;
	auto down = vec.size() - 1;
	
	while(up < down)
	{
		for(size_t i = up; i != down; i++)
		{
			if(!cmp(vec[i], vec[i + 1]))
			{
				swap(vec[i], vec[i + 1]);
			}
		}
		down--;
		for(size_t i = down; i != up; i--)
		{
			if(!cmp(vec[i - 1], vec[i]))
			{
				swap(vec[i - 1], vec[i]);
			}
		}
		up++;
	}

}

bool cmp1(int a, int b)
{
	return a < b;
}

void print(vector<int>const &vec)
{
	for(const auto &s: vec)
	{
		cout << s << " ";
	}
	cout <<endl;
}


int main(int argc, const char *argv[])
{
	srand(time(NULL));
	vector<int> vec;

	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	vec.push_back(rand()%100);
	
	cout << "before ";
	print(vec);
	bubble_sort(vec, cmp1);
	cout << "after ";
	print(vec);


	return 0;
}
