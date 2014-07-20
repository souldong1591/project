/*************************************************************************
	> File Name: SmartPtr_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月18日 星期五 19时08分15秒
 ************************************************************************/

#include "SmartPtr.h"

SmartPtr::SmartPtr(Animal *ptr)
	:ptr_(ptr)
{}

SmartPtr::~SmartPtr()
{
	delete ptr_;
}

Animal &SmartPtr::operator * ()
{
	return *ptr_;
}

const Animal &SmartPtr::operator * () const
{
	return *ptr_;
}

Animal *SmartPtr::operator -> ()
{
	return ptr_;
}

const Animal *SmartPtr::operator -> () const
{
	return ptr_;
}


