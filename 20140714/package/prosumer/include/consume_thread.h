#ifndef __CONSUME_THREAD_H__
#define __CONSUME_THREAD_H__ 

#include <pthread.h>

class Buffer;

class ConsumeThread
{
	public:
		ConsumeThread(Buffer &buffer);
		
		void start();
		static void *threadFunc(void *arg);
		void run();
		void join();

	private:
		pthread_t tid_;
		Buffer &buffer_;
};



#endif  /*__CONSUME_THREAD_H__*/
