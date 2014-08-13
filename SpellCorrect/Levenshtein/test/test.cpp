/*************************************************************************
	> File Name: test.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月11日 星期一 16时25分44秒
 ************************************************************************/

#include<vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;


int my_cmp(pair<string,int> p1,pair<string,int>  p2)
{
	return p1.second > p2.second;
}
int main(int argc,char** argv)
{
	vector<pair<string,int> > m_vector;

	m_vector.push_back(make_pair("a",1));
	m_vector.push_back(make_pair("c",3));
	m_vector.push_back(make_pair("b",2));
	sort(m_vector.begin(),m_vector.end(),my_cmp);
	cout << m_vector[0].first<< "  " << m_vector[1].first << "  " << m_vector[2].first << std::endl;
}
