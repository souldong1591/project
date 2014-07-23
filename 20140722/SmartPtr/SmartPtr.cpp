/*************************************************************************
	> File Name: SmartPtr.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 16时55分27秒
 ************************************************************************/

#include "SmartPtr.h"

SmartPtr::SmartPtr():
	ptr_(NULL)
{}

SmartPtr::SmartPtr(Animal *ptr):
	ptr_(ptr)
{}

SmartPtr::~SmartPtr()
{
	delete ptr_;
}

void SmartPtr::resetPtr(Animal *ptr)
{
	if(ptr_ != ptr)
	{
		delete ptr_;
		ptr_ = ptr;
	}
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
