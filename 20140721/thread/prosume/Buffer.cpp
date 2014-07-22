/*************************************************************************
	> File Name: Buffer.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月21日 星期一 20时52分27秒
 ************************************************************************/

#include "Buffer.h"
#include <iostream>
using namespace std;

Buffer::Buffer(size_t size):
	queue_(),
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
	bool ret = queue_.empty();
	mutex_.unlock();
	return ret;
}

bool Buffer::isFull() const
{
	mutex_.lock();
	bool ret = queue_.size() >= size_;
	mutex_.unlock();
	return ret;
}

void Buffer::produce(int data)
{
	mutex_.lock();
	while(queue_.size() >= size_)
	{
		empty_.wait();
	}
	queue_.push(data);
	cout << "produce a data: " << data << endl;
	cout << "produce size = " << queue_.size() << endl;
	full_.notify();
	mutex_.unlock();
}

int Buffer::consume()
{
	mutex_.lock();
	while(queue_.empty())
	{
		full_.wait();
	}
	int ret = queue_.front();
	queue_.pop();
	cout << "\t consume a data: " << ret << endl;
	cout << "\t consume size = " << queue_.size() << endl;
	empty_.notify();
	mutex_.unlock();
	return ret;
}
