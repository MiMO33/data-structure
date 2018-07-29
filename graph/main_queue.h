#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define ERROR 0
#define MAX_SIZE 20

typedef int status;

/*定义队列*/
typedef struct QNode{
    int Qarr[MAX_SIZE];
    int tail,head;
    int size;
}QNode,*Queue;

void InitQueue(Queue *Q){
    (*Q) = (QNode *)malloc(sizeof(QNode));
    if(*Q){
        (*Q)->size = 0;
        (*Q)->head = 0;
        (*Q)->tail = 0;
    }
}

/*入队列*/
void EnterQueue(Queue Q, int data){
    if((Q->tail +1) % MAX_SIZE == Q->head){
        printf("队列已经满!!\n");
        return;
    }
    Q->Qarr[Q->tail] = data;
    Q->size++;
    Q->tail = (Q->tail +1) % MAX_SIZE;
    return;
}

void OutQueue(Queue Q, int *data){
    if(Q->head == Q->tail){
        printf("队列为空!!\n");
        return;
    }
    (*data) = Q->Qarr[Q->head];
    Q->size--;
    Q->head = (Q->head +1) % MAX_SIZE;
    return;
}

int isEmpty(Queue Q){
    if(Q->head == Q->tail)return 1;
    return 0;
}