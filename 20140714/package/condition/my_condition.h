#ifndef __MY_CONDITION_H__
#define __MY_CONDITION_H__ 

#include <pthread.h>
#include <stdexcept>

class Condition
{
	public:
		Condition()
		{
			if(pthread_cond_init(&con_, NULL))
			{
				throw std::runtime_error("init failed");
			}
		}

		virtual ~Condition()
		{
			if(pthread_cond_destroy(&con_))
			{
				throw std::runtime_error("destroy failed");
			}
		}
		
		void wait(pthread_mutex_t mutex)
		{
			if(pthread_cond_wait(&con_, &mutex))
			{
				throw std::runtime_error("wait failed");
			}
		}

		void signal()
		{
			if(pthread_cond_signal(&con_))
			{
				throw std::runtime_error("signal failed");	
			}

		}
		
		void broadcast()
		{
			if(pthread_cond_broadcast(&con_))
			{
				throw std::runtime_error("broadcast failed");
			}
		}


		
	private:
		pthread_cond_t con_;

};



#endif  /*__MY_CONDITION_H__*/
