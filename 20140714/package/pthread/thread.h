#ifndef __PTHREAD_H__
#define __PTHREAD_H__ 

#include <pthread.h>

class Thread
{
	public:
		Thread();
		virtual ~Thread();
		void start();
		static void *threadFunc(void *arg);
		void run();
		void join();
	private:
		pthread_t tid_;
		int a_;
};



#endif  /*__PTHREAD_H__*/
