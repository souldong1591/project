#ifndef __FACTORY_H__
#define __FACTORY_H__ 

#include <vector>
#include "buffer.h"
#include "produce_thread.h"
#include "consume_thread.h"

class Factory
{
	public:
		Factory(size_t bufferSize,
				size_t producerNum,
				size_t consumerNum);

		void start();
	private:
		size_t bufferSize_;
		Buffer buffer_;
		size_t producerNum_;
		size_t consumerNum_;
		std::vector<ProduceThread> produceThreads_;
		std::vector<ConsumeThread> consumeThreads_;
};


#endif  /*__FACTORY_H__*/
