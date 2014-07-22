#ifndef __MYCONDITION_H__
#define __MYCONDITION_H__ 

#include <pthread.h>
class MutexLock;

class Condition
{
	public:
		Condition(MutexLock &lock);
		~Condition();
		void wait();
		void notify();
		void notifyAll();
	private:
		pthread_cond_t con_;
		MutexLock &lock_;
};




#endif  /*__MYCONDITION_H__*/
