#ifndef QUEUE_H_
#define QUEUE_H_ 

#include <stddef.h>
#include <stdbool.h>
typedef void* (*task_callback) (void*);

typedef struct
{
	task_callback task_func_;
	void *arg_;
}task_t;

typedef struct Node
{
	task_t data_;
	struct Node *next_;
}Node, *pNode;

typedef struct Queue
{
	pNode head_;
	pNode tail_;
	size_t size_;
}Queue, *pQueue;

void queue_init(pQueue q);

void queue_push(pQueue q, task_t data);

task_t queue_pop(pQueue q);

task_t queue_front(const pQueue q);

task_t queue_back(const pQueue q);

bool queue_empty(const pQueue q);

size_t queue_getSize(pQueue q);

void queue_clear(pQueue q);

void queue_destroy(pQueue q);
#endif  /*QUEUE_H_*/
