#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_ 

#include "queue.h"
#define ERR_EXIT(m) \
	do\
	{ \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

#define THREAD_POOL_SIZE 5
#define TRUE 1
#define FALSE 0

typedef struct 
{
	size_t size_;
	bool is_start_;
	pthread_t *threads_;
	pthread_mutex_t mutex_;
	pthread_cond_t cond_;
	Queue queue_;
}pool_t;


void thread_pool_init(pool_t *pool, size_t size);

void thread_pool_destroy(pool_t *pool);

void thread_pool_start(pool_t *pool);

void thread_pool_stop(pool_t *pool);

bool thread_pool_is_start(const pool_t *pool);

size_t thread_pool_get_task_queue_size(pool_t *pool);

void thread_pool_add_task_to_queue(pool_t *pool, task_t task);

bool thread_pool_get_task_from_queue(pool_t *pool, task_t *task);



#endif  /*THREAD_POOL_H_*/
