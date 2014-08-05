/*************************************************************************
	> File Name: Queue.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年08月01日 星期五 17时07分07秒
 ************************************************************************/

#include "Queue.h"
#include <assert.h>

Queue::Queue()
	:head_(NULL), tail_(NULL), size_(0)
{}

Queue::Queue(const Queue &other)
	:head_(NULL), tail_(NULL), size_(0)
{
	Node *pt = other.head_;
	while(pt != NULL)
	{
		push(pt->tsk_);
		pt = pt->next_;
		size_++;
	}
}
Queue &Queue::operator = (const Queue &other)
{
	if(this != &other)
	{
		head_ = tail_ = NULL;
		size_ = 0;
		Node *pt = other.head_;
		while(pt != NULL)
		{
			push(pt->tsk_);
			pt = pt->next_;
			size_++;
		}
	}
}

Queue::~Queue()
{
	clear();
}

void Queue::push(const Task_t &tsk)
{
	Node *pt = new Node;
	pt->tsk_ = tsk;
	pt->next_ = NULL;
	if(empty())
		head_ = tail_ = pt;
	else
	{
		tail_->next_ = pt;
		tail_ = pt;
	}
	size_++;
}

void Queue::pop()
{
	assert(!empty());
	Node *pt = head_;
	head_ = head_->next_;
	delete pt;
	size_--;
}

Task_t Queue::front() const
{
	assert(!empty());
	return head_->tsk_;
}

Task_t Queue::back() const
{
	assert(!empty());
	return tail_->tsk_;
}

bool Queue::empty() const
{
	return head_ == NULL;
}

size_t Queue::size() const
{
	return size_;
}

void Queue::clear()
{
	while(!empty())
		pop();
}

