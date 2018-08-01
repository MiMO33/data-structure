#include"merge_sort.h"

static void swap( void* a, void* b, const size_t element_size)
{
    void* temp = malloc(element_size);
    memcpy(temp, a, element_size);
    memcpy(a, b, element_size);
    memcpy(b, temp, element_size);
}

static merge(void* base,
             size_t length,
             const size_t element_size, 
             int (compare)(void* a, void* b))
{
    void* extra = malloc(length * element_size);
    void *left, *right, *p = extra;
    void* end = extra + length * element_size;
    while(p < ){
        if(*right > end || compare())
    }
}

void merge_sort(void* base, 
                const size_t length, 
                const size_t element_size, 
                int (compare)(void* a, void* b))
{
    size_t step, i;
    for(step = 1; step < length; step *= 2){
        for(i = 0; i < length;i += step){
            merge(base, step, element_size, compare);
        }
    }
}