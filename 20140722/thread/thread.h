#ifndef __THREAD_H__
#define __THREAD_H__ 

#include <pthread.h>

class Thread
{
	public:
		virtual ~Thread(){}
		
		void start();
		static void *threadFunc(void *arg);
		virtual void run() = 0;

		void join();


	private:
		pthread_t tid_;
};






#endif  /*__THREAD_H__*/
