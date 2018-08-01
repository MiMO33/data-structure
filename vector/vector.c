#include "vector.h"

typedef struct vector{
    size_t capacity;          
    size_t element_size;
    size_t size;
    void* base;
}vector;

static void expand(struct vector* v)
{
    v->capacity *= 2;
    void* new_base = malloc(v->capacity * v->element_size);
    memcpy(new_base, v->base, v->size * v->element_size);
	free(v->base);
    v->base = new_base;
}

static void shrink(struct vector* v)
{
    v->capacity /= 2;
    void* new_base = malloc(v->capacity * v->element_size);
    memcpy(new_base, v->base, v->size * v->element_size);
	free(v->base);
    v->base = new_base;
}

static void resize(struct vector* v)
{
    if(v->size >= DS_VECTOR_CAPACITY * 2 && ((double)v->size / v->capacity) < 0.25){
        shrink(v);
    }else if(((double)v->size / v->capacity) > 0.75){
        expand(v);
    }
}

struct vector* vector_init(size_t element_size)
{
    struct vector* v = (struct vector*)malloc(sizeof(struct vector));
    v->element_size = element_size;
    v->capacity = DS_VECTOR_CAPACITY;
    v->base = (void*)malloc(v->element_size * v->capacity);
    v->size = 0;
}

size_t vector_size(const struct vector* v)
{
    assert(v);
    return v->size;
}

void* vector_get(const struct vector* v,const size_t r)
{
    assert(v);
    assert(r < v->size);

    void* result = malloc(v->element_size);
    void* start = v->base + r * v->element_size;
    memcpy(result, start, v->element_size);
    return result;
}

void vector_put(struct vector* v,const size_t r,const void* e)
{   
    assert(v && e);
    assert(r >= 0);

    void* dest = v->base + r * v->element_size ;
    memcpy(dest, e, v->element_size);
}

void vector_insert(struct vector* v,const size_t r,const void* e)
{
    assert(v && e);
    assert(r >= 0);
    resize(v);

    void* dest = v->base + (r + 1) * v->element_size;
    void* source = v->base + r * v->element_size;
    size_t length = (v->size - r) * v->element_size;
    memcpy(dest, source, length);
    dest -= v->element_size;
    memcpy(dest, e, v->element_size);
    v->size++;
}

void* vector_remove(struct vector* v, const size_t r)
{
    assert(v);
    assert(r >= 0);
    resize(v);

    void* result = malloc(v->element_size);
    void* source = v->base + r * v->element_size;
    memcpy(result, source, v->element_size);
	
    void* dest = v->base + r * v->element_size;
    source += v->element_size;
    size_t length = (v->size - r - 1) * v->element_size;
    memcpy(dest, source, length);
    v->size--;
    return result;
}

void vector_traverse(const struct vector* v, void (*callback) (void* element))
{   
    void* dest = malloc(v->element_size);
    void* source = v->base;
    for(size_t i = 0; i < v->size; i++){
        memcpy(dest, source + i * v->element_size, v->element_size);
        callback(dest);
    }
}

int vector_compare(void* a, void* b)
{
    return *(int*)a > *(int*)b;
}

void vector_sort(struct vector* v, int (*compare) (void* a, void* b))
{
    sort_bubble(v->base, v->size, v->element_size, compare);
}

void vector_free(vector* v){
    assert(v);
    free(v->base);
    free(v);
}