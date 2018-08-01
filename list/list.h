#include<stdlib.h>

#ifndef DS_LSIT_H__
#define DS_LSIT_H__

#ifdef __cplusplus
extern "C"{
#endif

typedef struct list list;

/*
 * 初始化list
 * 
 * @param element_size        list 容纳元素的内存长度                     
 * @return                    返回list指针
 */ 

struct list* list_init(const int element_size); 

/*
 * 查询list 的长度
 * 
 * @param l                   list的指针
 * @return                    此list 的长度
 */

int list_length(const list* l);

/*
 * 判断list是否为空            
 * 
 * @param l                   list的指针
 * return                     1 -> true, 0 -> false
 */

int list_empty(const list* l);

/*
 * 
 * 
 */ 


#ifdef __cplusplus
}
#endif

#endif /*DS_LISTH__*/