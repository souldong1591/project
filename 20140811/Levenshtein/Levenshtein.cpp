/*************************************************************************
	> File Name: Levenshtein.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月11日 星期一 09时36分27秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int edit(string s1, string s2)
{
	int max1 = s1.size();
	int max2 = s2.size();

	int **ptr = new int*[max1 + 1];
	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i] = new int[max2 + 1];
	}

	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i][0] = i;
	}

	for (int i = 0; i < max2 + 1; i++)
	{
		ptr[0][i] = i;
	}

	for (int i = 1; i < max1 + 1; i++)
	{
		for (int j = 1; j < max2 + 1; j++)
		{
			int d;
			int tmp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if(s1[i - 1] == s2[j - 1])
				d = 0;
			else
				d = 1;
			ptr[i][j] = min(tmp, ptr[i - 1][j - 1] + d);
		}
	}

	int dis = ptr[max1][max2];
	for (int i = 0; i < max1 + 1; i++)
	{
		delete[] ptr[i];
		ptr[i] = NULL;
	}
	delete[] ptr;
	ptr = NULL;

	return dis;
}

int main(int argc, const char *argv[])
{
	if(argc != 3)
		ERR_EXIT("EXE STRING STRING");
	string s1 = argv[1];
	string s2 = argv[2];
	cout << "Levenshtein : " << edit(s1, s2) << endl;
	return 0;
}
