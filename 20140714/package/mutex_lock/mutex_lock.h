#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__ 

#include <pthread.h>
#include <stdexcept>

class Mutex_lock
{
	public:
		Mutex_lock()
		{
			if(pthread_mutex_init(&lock_, NULL))
			{
				throw std::runtime_error("init failed");
			}
		}

		virtual ~Mutex_lock()
		{
			if(pthread_mutex_destroy(&lock_))
			{
				throw std::runtime_error("destroy failed");
			}
		}

		void lock()
		{
			if(pthread_mutex_lock(&lock_))
			{
				throw std::runtime_error("lock failed");
			}
		}

		void unlock()
		{
			if(pthread_mutex_unlock(&lock_))
			{
				throw std::runtime_error("unlock failed");
			}
		}
	private:
		pthread_mutex_t lock_;
};



#endif  /*__MUTEX_LOCK_H__*/
