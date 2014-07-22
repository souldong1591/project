#ifndef __THREAD_H__
#define __THREAD_H__ 
#include <pthread.h>
class Thread
{
	public:
		void start();
		static void *threadFunc(void *arg);
		virtual void run();
		void join();

	private:
		pthread_t tid_;
};

#endif  /*__THREAD_H__*/
