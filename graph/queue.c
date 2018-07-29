#include"queue.h"

/**
 * 初始化队列
 * @q: 需要初始化的队列指针
 **/
void init_queue(queue* q){
    q->list = (int*)malloc(sizeof(int) * DS_QUEUE_MAX_SIZE);
    q->head = 0;
    q->tail = 0;
}

/**
 * enter_queue:
 * @q: 插入的队列
 * @data: int型，需要插入的数据
 * 
 * 向队列中插入数据
 **/
void enter_queue(queue* q, int data){
    q->list[q->tail++] = data;
}

int out_queue(queue* q){
    return q->list[q->head++];
}