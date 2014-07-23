#ifndef __QUEUE_H__
#define __QUEUE_H__ 

#include <stddef.h>
#include <iostream>
#include <assert.h>
template <typename T>
class Queue;
template <typename T>
class Node
{
	public:
		friend class Queue<T>;
	private:
		T data_;
		Node<T> *next_;
};

template <typename T>
class Queue
{
	public:
		Queue();
		Queue(const Queue<T> &other);
		Queue &operator = (const Queue<T> &other);
		~Queue();
	
		void push(const T &data);
		void pop();
		T front() const;
		T back() const;
		bool empty() const;
		size_t size() const;
		void clear();
		void print() const;

	private:
		Node<T> *head_;
		Node<T> *tail_;
		size_t size_;
};

template <typename T>
inline Queue<T>::Queue():
	head_(NULL), tail_(NULL), size_(0)
{}

template <typename T>
inline Queue<T>::Queue(const Queue<T> &other):
	head_(NULL), tail_(NULL), size_(0)
{
	Node<T> *pt = other.head_;
	while(pt != NULL)
	{
		push(pt->data_);
		pt = pt->next_;
	}
}

template <typename T>
inline Queue<T> &Queue<T>::operator = (const Queue<T> &other)
{
	if(this != &other)
	{
		head_ = tail_ = NULL;
		size_ = 0;
		Node<T> *pt = other.head_;
		while(pt != NULL)
		{
			push(pt->data_);
			pt = pt->next_;
		}
	}
}

template <typename T>
inline Queue<T>::~Queue()
{
	clear();
}

template <typename T>
inline void Queue<T>::push(const T &data)
{
	Node<T> *pt = new Node<T>;
	pt->data_ = data;
	pt->next_ = NULL;
	if(empty())
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

template <typename T>
inline void Queue<T>::pop()
{
	assert(!empty());
	Node<T> *pt = head_;
	head_ = head_->next_;
	delete pt;
	size_--;
}

template <typename T>
inline T Queue<T>::front() const
{
	assert(!empty());
	return head_->data_;
}

template <typename T>
inline T Queue<T>::back() const
{
	assert(!empty());
	return tail_->data_;
}

template <typename T>
inline bool Queue<T>::empty() const
{
	return head_ == NULL;
}

template <typename T>
inline size_t Queue<T>::size() const
{
	return size_;
}

template <typename T>
inline void Queue<T>::clear()
{
	while(!empty())
	{
		pop();
	}
}

template <typename T>
inline void Queue<T>::print() const
{
	Node<T> *pt = head_;
	std::cout << "front: " << front() << "\tback: " << back() << std::endl;
	std::cout << "queue: ";
	while(pt != NULL)
	{
		std::cout << pt->data_ << "  ";
		pt = pt->next_;
	}
	std::cout << std::endl;
	
}

#endif  /*__QUEUE_H__*/
