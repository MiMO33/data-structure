#include<stdlib.h>
#include<string.h>

#ifndef DS_STATCK_H__
#define DS_STATCK_H__

#ifdef _cpluscplus
extern "C"{
#endif

typedef struct stack stack;

struct stack* stack_init(size_t element_size);
void stack_push(struct stack* s, void* data);
void* stack_pop(struct stack* s);
void* stack_top(struct stack* s);

#ifdef _cpluscplus
}
#endif

#endif /* DS_STACK_H__ */