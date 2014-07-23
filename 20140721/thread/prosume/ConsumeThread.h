#ifndef __CONSUMETHREAD_H__
#define __CONSUMETHREAD_H__ 

#include "thread.h"

class Buffer;

class ConsumeThread : public Thread
{
	public:
		ConsumeThread(Buffer &buffer);
		void run();
	private:
		Buffer &buffer_;
		
};




#endif  /*__CONSUMETHREAD_H__*/
