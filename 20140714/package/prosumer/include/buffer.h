#ifndef __BUFFER_H__
#define __BUFFER_H__ 

#include "queue.h"
#include "mutex_lock.h"
#include "my_condition.h"


class Buffer
{
	public:
		Buffer(size_t size);
		
		virtual ~Buffer();

		bool isEmpty() const;
		
		bool isFull() const;
	
		void produce(int data);

		int consume();


	private:
		Queue queue_;
		mutable Mutex_lock mutex_;
		Condition full_;
		Condition empty_;
		size_t size_;
};





#endif  /*__BUFFER_H__*/
