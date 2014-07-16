/*************************************************************************
	> File Name: queue_fun.cpp
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月14日 星期一 15时14分56秒
 ************************************************************************/

#include "queue.h"
#include <iostream>
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
	if(tail_ == NULL)
	{
		head_ = tail_ = pt;
	}
	else
	{
		tail_->next_ = pt;
		tail_ = tail_->next_;
	}
	size_++;
}

void Queue::pop()
{
	if(!isEmpty())
	{
		Nodeptr pt = head_;
		head_ = head_->next_;
		delete pt;
		size_--;
	}
	else
	{
		cout << "Queue is empty!!" << endl;
	}
}

int Queue::top() const
{
	if(!isEmpty())
	{
		return head_->data_;
	}
	cout << "Queue is empty!!" << endl;
	return 0;	
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
