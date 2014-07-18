#ifndef __QUEUE_H__
#define __QUEUE_H__ 
#include <stddef.h>
class Node
{
	public:
		friend class Queue;
	private:
		int data_;
		Node *next_;
};

typedef Node* NodePtr;

class Queue
{
	public:
		Queue();
		Queue(const Queue &other);
		Queue &operator = (const Queue &other);
		~Queue();
		
		void push(int data);
		void pop();
		int front() const;
		int back() const;
		bool empty() const;
		size_t size() const;
		void clear();
		void print() const;
	private:
		NodePtr head_;
		NodePtr tail_;
		size_t size_;
};





#endif  /*__QUEUE_H__*/
