/*
 * @author      Qi Tianyuan
 * @e-mail      qitianyuan@foxmail.com
 */

#include<stdlib.h>
#include<assert.h>
#include<string.h>

#ifndef DS_VECTOR_H__
#define DS_VECTOR_H__

#ifndef DS_VECTOR_CAPACITY
#define DS_VECTOR_CAPACITY 100
#endif

typedef struct vector vector;

#ifdef __cplusplus
extern "C"{
#endif

/*
 * 初始化当前向量
 * 
 * @param element_size        元素的位数 
 * @return                    向量的指针
 */

vector* vector_init(const size_t element_size);

/*
 * 返回当前向量的元素个数（元素总数）
 *  
 * @param v                   需要处理的向量指针
 * @return                    当前向量的个数
 * 
 */

size_t vector_size(const struct vector* v);

/*
 * 获取与 r 相等的元素
 * 
 * @param v                   需要处理的向量的指针 
 * @param r                   需要返回的向量的轶
 * @return                    与 r 相等的向量的序号，不存在则返回 -1
 * 
 */

void* vector_get(const struct vector* v,const size_t r);

/*
 * 用 e 替换轶为 r 的元素的内容
 * 
 * @param v                   需要处理的向量的指针 
 * @param r                   指定插入元素的轶
 * @param e                   引入元素所在的指针
 * 
 */

void vector_put(struct vector* v,const size_t r,const void* e);

/*
 * e作为轶为 r 的元素插入，原元素依次后移
 * 
 * @param v                   需要处理的向量的指针 
 * @param r                   指定插入元素的轶
 * @param e                   引入元素所在的指针
 * 
 */

void vector_insert(struct vector* v, const size_t r,const void* e);

/*
 * 删除轶为 r 的元素， 返回原先存放的元素
 * 
 * @param v                   需要处理的向量的指针 
 * @param r                   指定插入元素的轶
 * @return                    原先存放的元素
 */

void* vector_remove(struct vector* v, const size_t r);

/*
 * 遍历此向量
 * 
 * @param v                   被遍历的向量
 * @param callback            回调函数
 */

void vector_traverse(const struct vector* v, void (*callback) (void* element));


#ifdef __cplusplus
}
#endif

#endif