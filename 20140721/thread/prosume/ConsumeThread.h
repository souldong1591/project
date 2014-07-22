#ifndef __CONSUMETHREAD_H__
#define __CONSUMETHREAD_H__ 

#include "thread.h"

class Buffer;

class ComsumeThread : public Thread
{
	public:
		ComsumeThread(Buffer &buffer);
		void run();
	private:
		Buffer &buffer_;
		
};




#endif  /*__CONSUMETHREAD_H__*/
