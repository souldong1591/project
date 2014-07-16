/*************************************************************************
	> File Name: queue_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 15时14分56秒
 ************************************************************************/

#include "queue.h"
#include <iostream>
#include <assert.h>
using namespace std;
Queue::Queue()
	:head_(NULL), tail_(NULL), size_(0)
{}

Queue::~Queue()
{
	clear();
}

void Queue::push(int data)
{
	Nodeptr pt = new Node;
	pt->data_ = data;
	pt->next_ = NULL;
	if(isEmpty())
	{
		head_ = tail_ = pt;
	}
	else
	{
		tail_->next_ = pt;
		tail_ = pt;
	}
	size_++;
}

void Queue::pop()
{
	assert(!isEmpty());
	Nodeptr pt = head_;
	head_ = head_->next_;
	delete pt;
	size_--;
}

int Queue::top() const
{
	assert(!isEmpty());
	return head_->data_;
}

void Queue::clear()
{
	while(!isEmpty())
	{
		pop();
	}

}

bool Queue::isEmpty() const
{
	return head_ == NULL;
}

size_t Queue::getSize() const
{
	return size_;
}

void Queue::print() const
{
	Nodeptr pt = head_;
	while(pt != NULL)
	{
		cout << pt->data_ << " ";
		pt = pt->next_;
	}
	cout << endl;
}
