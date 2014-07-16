#ifndef __MY_CONDITION_H__
#define __MY_CONDITION_H__ 

#include <pthread.h>

class Mutex_lock;

class Condition
{
	public:
		Condition(Mutex_lock &lock);		

		virtual ~Condition();	
		
		void wait();	

		void notify();	
		
		void notifyAll();
		
	private:
		pthread_cond_t con_;
		Mutex_lock &lock_;

};



#endif  /*__MY_CONDITION_H__*/
