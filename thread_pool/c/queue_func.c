/*************************************************************************
	> File Name: queue_func.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月25日 星期五 21时33分20秒
 ************************************************************************/

#include "queue.h"
#include <assert.h>
#include <stdlib.h>
void queue_init(pQueue q)
{
	q->head_ = q->tail_ = NULL;
	q->size_ = 0;
}

void queue_push(pQueue q, task_t data)
{
	pNode pt = (pNode)malloc(sizeof(Node));
	pt->data_ = data;
	pt->next_ = NULL;
	if(queue_empty(q))
		q->head_ = q->tail_ = pt;
	else
	{
		q->tail_->next_ = pt;
		q->tail_ = pt;
	}
	(q->size_)++;

}

task_t queue_pop(pQueue q)
{
	assert(!queue_empty(q));
	task_t data;
	pNode pt = q->head_;
	q->head_ = q->head_->next_;
	data = pt->data_;
	free(pt);
	(q->size_)--;
	return data;

}

task_t queue_front(const pQueue q)
{
	assert(!queue_empty(q));
	return q->head_->data_;
}

task_t queue_back(const pQueue q)
{
	assert(!queue_empty(q));
	return q->tail_->data_;
}

bool queue_empty(const pQueue q)
{
	return q->head_ == NULL;
}

size_t queue_getSize(pQueue q)
{
	return q->size_;
}

void queue_clear(pQueue q)
{
	while(!queue_empty(q))
		queue_pop(q);

}

void queue_destroy(pQueue q)
{
	queue_clear(q);
}
