#ifndef __BUFFER_H__
#define __BUFFER_H__ 

#include <queue>
#include "MutexLock.h"
#include "MyCondition.h"

class Buffer
{
	public:
		Buffer(size_t size);
		~Buffer();
		bool isEmpty() const;
		bool isFull() const;
		void produce(int data);
		int consume();


	private:
		std::queue<int> queue_;
		mutable MutexLock mutex_;
		Condition full_;
		Condition empty_;
		size_t size_;
};



#endif  /*__BUFFER_H__*/
