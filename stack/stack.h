#include<stdlib.h>
#include<string.h>

#ifndef DS_STATCK_H__
#define DS_STATCK_H__

#ifdef _cpluscplus
extern "C"{
#endif

typedef struct stack stack;

/* 
 * 初始化栈
 * 
 * @param element_size        元素的长度
 * @return                    向量的指针
 */

struct stack* stack_init(size_t element_size);

/* 
 * 初始化栈
 * 
 * @param s                   栈的指针
 * @param data                元素的指针
 */

void stack_push(struct stack* s, void* data);

/* 
 * 弹出栈顶元素
 * 
 * @param s                   栈的指针
 * @return                    返回元素的指针
 */

void* stack_pop(struct stack* s);

/* 
 * 读出栈顶元素
 * 
 * @param s                   栈的指针
 * @return                    返回元素的指针
 */

void* stack_top(struct stack* s);

/* 
 * 栈是否为空
 * 
 * @param s                   栈的指针
 * @return                    
 */

int stack_empty(struct stack* s);

#ifdef _cpluscplus
}
#endif

#endif /* DS_STACK_H__ */