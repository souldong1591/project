#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__ 

#include <pthread.h>
class MutexLock
{
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
		pthread_mutex_t *getMutexLockPtr();
	private:
		pthread_mutex_t lock_;
};




#endif  /*__MUTEXLOCK_H__*/
