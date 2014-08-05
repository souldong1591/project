/*************************************************************************
	> File Name: lcs_nr.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 15时55分25秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(const string &x, const string &y, int m, int n)
{
	int **LCS_memo;
	LCS_memo = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
		LCS_memo[i] = new int[n + 1];
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			LCS_memo[i][j] = 0;
		}
	}
	
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if(x[i - 1] == y[j - 1])
				LCS_memo[i][j] = LCS_memo[i - 1][j -1] + 1;
			else
			{
				LCS_memo[i][j] = LCS_memo[i - 1][j] > LCS_memo[i][j - 1] ?
					LCS_memo[i - 1][j] : LCS_memo[i][j - 1];
				
			}
		}
	}
	
	return LCS_memo[m][n];
	
}

int main(int argc, const char *argv[])
{
	string x(argv[1]);
	string y(argv[2]);
	cout << "lcs = " << LCS(x, y, x.size(), y.size()) << endl;
	return 0;
}
