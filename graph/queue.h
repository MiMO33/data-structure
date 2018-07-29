#ifndef DS_QUEUE_H__
#define DS_QUEUE_H__

#define DS_QUEUE_MAX_SIZE 1000

#include<stdlib.h>

typedef struct queue{
    int* list;
    int head, tail;
}queue;

void enter_queue(queue* q, int data);
int out_queue(queue* q);

#endif