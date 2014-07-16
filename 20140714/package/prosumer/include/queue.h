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

typedef Node* Nodeptr;

class Queue
{
	public:
		Queue();
		~Queue();

		void push(int data);
		void pop();
		int top() const;
		void clear();
		bool isEmpty() const;
		size_t getSize() const;
		void print() const;

	private:
		Nodeptr head_;
		Nodeptr tail_;
		size_t size_;
};



#endif  /*__QUEUE_H__*/
