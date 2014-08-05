#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_ 

#include <stddef.h>
#include "NonCopyable.h"
#include <pthread.h>
#include "Queue.h"
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

#define THREAD_POOL_SIZE 5

class Task_t;

class Thread_pool : private NonCopyable
{
	public:
		Thread_pool();
		~Thread_pool();
		void start();
		void stop();
		bool is_start();
		size_t get_task_queue_size();
		void add_task_to_queue(Task_t tsk);
		bool get_task_from_queue(Task_t *tsk);

	private:
		size_t size_;
		bool is_start_;
		pthread_t *threads_;
		pthread_mutex_t mutex_;
		pthread_cond_t cond_;
		Queue queue_;
		static void *thread_pool_func(void *arg);
};







#endif  /*THREAD_POOL_H_*/
