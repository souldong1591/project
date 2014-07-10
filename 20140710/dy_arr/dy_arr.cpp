/*************************************************************************
	> File Name: dy_arr.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月10日 星期四 20时29分17秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	int **arr = new int*[3];
	for(int ix = 0; ix != 3; ix++)
	{
		arr[ix] = new int[2];
	}

	int k = 0;
	for(int ix = 0; ix != 3; ix++)
	{
		for(int iy = 0; iy != 2; iy++)
		{
			arr[ix][iy] = k;
			++k;
			cout << arr[ix][iy] << " ";
		}
		cout << endl;
	}

	for(int ix = 0; ix != 3; ix++)
	{
		delete[] arr[ix];
	}
	delete[] arr;



	return 0;
}
