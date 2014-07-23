/*************************************************************************
	> File Name: Handle_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月22日 星期二 14时40分26秒
 ************************************************************************/

#include "Handle.h"
#include "Animal.h"

Handle::Handle():
	ptr_(NULL)
{}

Handle::Handle(const Animal &a):
	ptr_(a.copy())
{}

Handle::Handle(const Handle &other):
	ptr_(other.ptr_->copy())
{}

Handle::~Handle()
{
	delete ptr_;
}

Handle &Handle::operator = (const Handle &other)
{
	if(this != &other)
	{
		delete ptr_;
		ptr_ = other.ptr_->copy();
	}
	return *this;
}

Animal *Handle::operator -> ()
{
	return ptr_;
}

const Animal *Handle::operator -> () const
{
	return ptr_;
}
