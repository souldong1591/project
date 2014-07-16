#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__ 

#include <pthread.h>

class Mutex_lock
{
	public:
		Mutex_lock();
		
		virtual ~Mutex_lock();
		

		void lock();
		

		void unlock();
		
		pthread_mutex_t *getMutexLockPtr();
		



	private:
		pthread_mutex_t lock_;
};



#endif  /*__MUTEX_LOCK_H__*/
