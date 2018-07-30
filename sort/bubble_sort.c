#include"bubble_sort.h"

static void swap( void* a, void* b, const size_t element_size)
{
    void* temp = malloc(element_size);
    memcpy(temp, a, element_size);
    memcpy(a, b, element_size);
    memcpy(b, temp, element_size);
}

void sort_bubble(void* base, 
          const size_t length, 
          const size_t element_size, 
          int (*compare)(void* a, void* b))
{
    size_t i, j;
    void* a = base;
    void* b = base + element_size;
    for( i = 0; i < length; i++){
        for(a = base; a < base + length * element_size; a += element_size){
            if(compare(a, a + element_size)){
                swap(a, a + element_size, element_size);
            }
        }
    }
}