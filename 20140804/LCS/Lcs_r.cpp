/*************************************************************************
	> File Name: Lcs.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月04日 星期一 11时07分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;


int memo[100][100];

int LCS(const string &x, const string &y, int i, int j)
{
	if(i == 0 || j == 0)
		return 0;
	if(memo[i][j] != -1)
		return memo[i][j];
	
	if(x[i - 1] == y[j - 1])
	{
		memo[i][j] = LCS(x, y, i - 1, j - 1) + 1;
		return memo[i][j];
	}
	else
	{
		memo[i][j] = (LCS(x, y, i - 1, j) > LCS(x, y, i, j - 1)
					? LCS(x, y, i - 1, j) : LCS(x, y, i, j -1));

		return memo[i][j];
	}
}

int main(int argc, const char *argv[])
{
	string x(argv[1]);
	string y(argv[2]);
	memset(memo, -1, sizeof(memo));
	int n = LCS(x, y, x.size(), y.size());
	cout << "lcs = " << n << endl;
	return 0;

}
