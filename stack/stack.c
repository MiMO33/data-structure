#include"stack.h"

#define DS_STACK_CAPACITY 100

typedef struct stack{
    size_t element_size;
    size_t top;
    size_t capacity;
    void* base;
}stack;

struct stack* stack_init(size_t element_size){
    struct stack* s = malloc(sizeof(stack));
    s->element_size = element_size;
    s->capacity = DS_STACK_CAPACITY;
    s->base = malloc(s->capacity * element_size);
    s->top = -1;
    return s;
}

static void expand(struct stack* s)
{
    s->capacity *= 2;
    void* new_base = malloc(s->capacity * s->element_size);
    memcpy(new_base, s->base, s->top * s->element_size);
	free(s->base);
    s->base = new_base;
}

static void shrink(struct stack* s)
{
    s->capacity /= 2;
    void* new_base = malloc(s->capacity * s->element_size);
    memcpy(new_base, s->base, s->top * s->element_size);
	free(s->base);
    s->base = new_base;
}

static void resize(struct stack* s){
    if(s->top == -1){
        return;
    }
    double rate = (double)s->top / s->capacity;
    if(s->capacity > 100 && rate < 0.25){
        shrink(s);
    }else if(rate > 0.75){
        expand(s);
    }
}

void stack_push(struct stack* s, void* data)
{
    resize(s);
    s->top++;
    memcpy(s->base + s->element_size * s->top, data, s->element_size);
}

void* stack_pop(struct stack* s)
{
    void* re = malloc(s->element_size);
    memcpy(re, s->base + s->top * s->element_size, s->element_size);
    s->top--;
    return re;   
}

void* stack_top(struct stack* s)
{
    void* re = malloc(s->element_size);
    memcpy(re, s->base + s->top * s->element_size, s->element_size);
}