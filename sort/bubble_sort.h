#include<string.h>
#include<stdlib.h>
#include<assert.h>

#ifndef DS_BUBBLE_SORT_H__
#define DS_BUBBLE_SORT_H__

/*
 * 起泡排序
 * @param base                开始的地址
 * @param length              所含元素的数量
 * @param element_size        元素的长度
 * @param int*(compare)       判断大小的函数
 * 
 */

void sort_bubble(void* base, 
          const size_t length, 
          const size_t element_size, 
          int (compare)(void* a, void* b));

#endif