#ifndef QUEUE_H_
#define QUEUE_H_ 

#include <stddef.h>
#include <functional>
class Task_t
{
	friend class Node;
	public:
		std::function<void* (void*)> fp_;
		void *arg_;
};

class Node
{
	friend class Queue;
	public:
		Task_t tsk_;
		Node *next_;
};

class Queue
{
	public:
		Queue();
		Queue(const Queue &other);
		Queue &operator = (const Queue &other);
		virtual ~Queue();

		void push(const Task_t &tsk);
		void pop();
		Task_t front() const;
		Task_t back() const;
		bool empty() const;
		size_t size() const;
		void clear();

	private:
		Node *head_;
		Node *tail_;
		size_t size_;
};


#endif  /*QUEUE_H_*/
