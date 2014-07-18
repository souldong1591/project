/*************************************************************************
	> File Name: queue_func.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月17日 星期四 22时10分54秒
 ************************************************************************/

#include "queue.h"
#include <assert.h>
#include <iostream>
using namespace std;

Queue::Queue()
	:head_(NULL), tail_(NULL), size_(0)
{}

Queue::Queue(const Queue &other)
	:head_(NULL), tail_(NULL), size_(0)
{
	NodePtr pt = other.head_;
	while(pt != NULL)
	{
	/*	if(head_ == NULL)
		{
			head_ = tail_ = pt;
		}
		else
		{
			tail_->next_ = pt;
			tail_ =pt;
		}*/
		push(pt->data_);
		pt = pt->next_;
	}
}

Queue &Queue::operator = (const Queue &other)
{
	if(this != &other)
	{
		head_ = tail_ = NULL;
		size_ = 0;
		NodePtr pt = other.head_;
		
		while(pt != NULL)
		{
			/*
			if(head_ == NULL)
			{
				head_ = tail_ = pt;
			}
			else
			{
				tail_->next_ = pt;
				tail_ =pt;
			}
			pt = pt->next_;*/
			push(pt->data_);
			pt = pt->next_;
		}
	}
}

Queue::~Queue()
{
	clear();
}

void Queue::push(int data)
{
	NodePtr pt = new Node;
	pt->data_ = data;
	pt->next_ = NULL;
	if(empty())
	{
		head_= tail_ = pt;
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
	assert(!empty());
	NodePtr pt = head_;
	head_ = head_->next_;
	delete pt;
	size_--;
}

int Queue::front() const
{
	assert(!empty());
	return head_->data_;
}

int Queue::back() const
{
	assert(!empty());
	return tail_->data_;
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
	{
		pop();	
	}
}

void Queue::print() const
{
	NodePtr pt = head_;
	cout << "front: " << front() << endl;
	cout << "queue: ";
	while(pt != NULL)
	{
		cout << pt->data_ << "  ";
		pt = pt->next_;
	}
	cout << endl;
	cout << "back: " << back() << endl;
}
