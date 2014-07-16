#ifndef __PRODUCE_THREAD_H__
#define __PRODUCE_THREAD_H__ 

#include <pthread.h>

class Buffer;

class ProduceThread
{
	public:
		ProduceThread(Buffer &buffer);
		
		void start();
		static void *threadFunc(void *arg);
		void run();
		void join();


	private:
		pthread_t tid_;
		Buffer &buffer_;
};





#endif  /*__PRODUCE_THREAD_H__*/
