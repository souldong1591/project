/*************************************************************************
  > File Name: buffer_fun.cpp
  > Author: Soul
  > Mail:souldong1591@gmail.com 
  > Created Time: 2014年07月15日 星期二 11时31分02秒
 ************************************************************************/

#include "buffer.h"
#include <iostream>
using namespace std;

Buffer::Buffer(size_t size)
	:queue_(),
	 mutex_(), 
	 full_(mutex_), 
	 empty_(mutex_), 
	 size_(size)
{}

Buffer::~Buffer()
{}

bool Buffer::isEmpty() const
{
	mutex_.lock();
	bool ret = queue_.isEmpty();
	mutex_.unlock();
	return ret;
}

bool Buffer::isFull() const
{
	mutex_.lock();
	bool ret = queue_.getSize() >= size_;
	mutex_.unlock();
	return ret;

}

void Buffer::produce(int data)
{
	mutex_.lock();
	while(queue_.getSize() >= size_)
	{
		empty_.wait();
	}
	queue_.push(data);
	cout << "produce a data: " << data << endl;
	cout << "produce size = " << queue_.getSize() << endl;
	full_.notify();
	mutex_.unlock();
}

int Buffer::consume()
{
	mutex_.lock();
	while(queue_.isEmpty())
	{
		full_.wait();
	}
	int ret = queue_.top();
	queue_.pop();
	cout << "           consume a data: " << ret << endl;
	cout << "           consume size = " << queue_.getSize() << endl;

	empty_.notify();
	mutex_.unlock();
	return ret;
}

