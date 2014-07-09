/*************************************************************************
	> File Name: queue_fun.c
	> Author: Soul
	> Mail:souldong1591@gmail.com 
	> Created Time: 2014年07月09日 星期三 22时56分59秒
 ************************************************************************/


#include "queue.h"
#include <stdlib.h>
#include <assert.h>



void queue_init(Queue *Q){
    Q->head_ = NULL;
    Q->tail_ = NULL;
    Q->size_ = 0;
}
void queue_destroy(Queue *Q){
    queue_clear(Q);
}
void queue_push(Queue *Q, int data){
    p_node pt = (p_node)malloc(sizeof(q_node));
    pt->data_ = data;
    pt->next_ = NULL;
    if(queue_is_empty(Q)){
        Q->head_ = Q->tail_ = pt;
    }else{
        Q->tail_->next_ = pt;
        Q->tail_ = pt;
    }
    ++Q->size_;
}
int queue_top(const Queue *Q){
    assert(!queue_is_empty(Q));
    return Q->head_->data_;
}
void queue_pop(Queue *Q){
    assert(!queue_is_empty(Q));
    p_node pt = Q->head_;
    Q->head_ = Q->head_->next_;
    free(pt);
    --Q->size_;
}
void queue_clear(Queue *Q){
    while(!queue_is_empty(Q)){
        queue_pop(Q);
    }
}
int queue_is_empty(const Queue *Q){
    return Q->head_ == NULL;
}
int queue_get_size(const Queue *Q){
    return Q->size_;
}

